/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 14:42
 * Description : 
*********************************************************************/

#include "AOIService.h"

#include <exception>
#include <memory>

#include "NotImplementException.h"
#include "IAOILocation.h"
#include "IAOIManager.h"
#include "AOIActorGUID.h"
#include "AOIActor.h"
#include "AOIActorCell.h"
#include "AOIRegion.h"

extern "C" OPERA_LIB_API aoi::IAOIService* CreateAOIService()
{
	return new aoi::AOIService();
}

extern "C" OPERA_LIB_API void ReleaseAOIService(aoi::IAOIService* obj)
{
	if (obj != nullptr) {
		delete obj;
		obj = nullptr;
	}
}

namespace aoi
{

	void AOIService::Init(aoi::IAOIManager* aoi_manager, 
		aoi::OnEnteredHandler on_entered_handler, 
		aoi::OnLeftHandler on_left_handler, 
		aoi::OnMovedHandler on_moved_handler)
	{
		set_aoi_manager(aoi_manager);

		aoi_event_system.AddOnEnteredHandler(on_entered_handler);
		aoi_event_system.AddOnLeftHandler(on_left_handler);
		aoi_event_system.AddOnMovedHandler(on_moved_handler);

		OnInit();
	}

	void AOIService::OnInit()
	{
		
	}

	aoi::AOIActor* AOIService::Add(const aoi::IAOILocation& actor_location)
	{
		// ��aoi������ ����ʵ�ʵ�ת������
		auto aoiRegion = aoi_manager_->GetAOIRegion(actor_location);
		if (aoiRegion == nullptr) {
			// todo ������aoi����
		}

		auto actorCell = aoi_manager_->GetAOICell(aoiRegion, actor_location);
		if (actorCell == nullptr) {
			// todo ����cell
			aoiRegion->AddCell(actorCell);
		}

		// ����actor����ӵ� ������
		auto newActor = aoi_manager_->CreateActor();
		newActor->set_guid(aoi_actor_guid_generator_.Next());
		newActor->set_location(actor_location);
		newActor->set_aoi_cell(actorCell);
		actorCell->AddActor(newActor);

		// ��ʼ����aoi�¼�
		OnAOIActorAdded(aoiRegion, actorCell, newActor);

		return newActor;
	}

	void AOIService::OnAOIActorAdded(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, aoi::AOIActor* new_aoi_actor)
	{
		aoi_manager_->ForeachAOIActorInRange(aoi_region, aoi_cell, [&](aoi::AOIActor* actor) {
			// ��������
			if (actor == new_aoi_actor)
				return;

			aoi_event_system.OnActorEntered(new_aoi_actor, actor);
			aoi_event_system.OnActorEntered(actor, new_aoi_actor);
		});
	}

	void AOIService::Remove(const aoi::GUID& actor_guid)
	{
		// �����Ƿ��ж�Ӧ��actor
		auto actor = aoi_manager_->get_aoi_actor(actor_guid);
		if (actor == nullptr)
			return;

		// todo ���б��Ƴ�
		auto actorCell = actor->get_aoi_cell();
		if (actorCell == nullptr)
			return;

		actorCell->RemoveActor(actor);

		// ����aoi�¼�
		OnAOIActorRemoved(actorCell->get_aoi_region(), actorCell, actor);
	}

	void AOIService::OnAOIActorRemoved(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, aoi::AOIActor* removed_aoi_actor)
	{
		// ��ӳ���б��Ƴ�
		aoi_manager_->RemoveActor(removed_aoi_actor);

		// ���cellΪ�գ������
		if (aoi_cell->IsEmpty()) {
			aoi_region->RemoveActorCell(aoi_cell);
		}

		aoi_manager_->ForeachAOIActorInRange(aoi_region, aoi_cell, [&](aoi::AOIActor* actor) {

			aoi_event_system.OnActorLeft(removed_aoi_actor, actor);
			aoi_event_system.OnActorLeft(actor, removed_aoi_actor);
		});
	}

	void AOIService::Move(const aoi::GUID actor_guid, const aoi::IAOILocation& target_loc)
	{
		// �����Ƿ��ж�Ӧ��actor
		auto actor = aoi_manager_->get_aoi_actor(actor_guid);
		if (actor == nullptr)
			return;

		// ��ǰcell
		auto currentCell = actor->get_aoi_cell();
		if (currentCell == nullptr)
			return;

		// ��cell
		auto newCell = aoi_manager_->GetAOICell(currentCell->get_aoi_region(), target_loc);
		if (newCell == nullptr)
			return;

		// �뿪��aoi��Χ��cells
		std::vector<aoi::AOIActorCell*> exited_cells;
		// ��Ȼ��aoi��Χ�ڵ�cells
		std::vector<aoi::AOIActorCell*> remain_cells;
		// �½��뵽aoi��Χ�ڵ�cells
		std::vector<aoi::AOIActorCell*> entered_cells;

		if (!aoi_manager_->DiffActerCellsOnAOIRange(currentCell, newCell, get_aoi_range(), exited_cells, remain_cells, entered_cells)) {
			// todo
			return;
		}

		currentCell->RemoveActor(actor);
		newCell->AddActor(actor);
		
		for (auto cell : exited_cells){
			auto actor_iter = cell->get_actor_iter_begin(); 
			auto actor_iter_end = cell->get_actor_iter_end();
			
			for (; actor_iter != actor_iter_end; ++actor_iter) {
				aoi_event_system.OnActorLeft(*actor_iter, actor);
				aoi_event_system.OnActorLeft(actor, *actor_iter);
			}
		}

		for (auto cell : entered_cells) {
			auto actor_iter = cell->get_actor_iter_begin();
			auto actor_iter_end = cell->get_actor_iter_end();

			for (; actor_iter != actor_iter_end; ++actor_iter) {
				aoi_event_system.OnActorEntered(*actor_iter, actor);
				aoi_event_system.OnActorEntered(actor, *actor_iter);
			}
		}

		for (auto cell : remain_cells) {
			auto actor_iter = cell->get_actor_iter_begin();
			auto actor_iter_end = cell->get_actor_iter_end();

			for (; actor_iter != actor_iter_end; ++actor_iter) {
				aoi_event_system.OnActorMoved(*actor_iter, actor);
				aoi_event_system.OnActorMoved(actor, *actor_iter);
			}
		}
	}

}