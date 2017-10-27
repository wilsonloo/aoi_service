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

namespace aoi
{

	void AOIService::Init(OnEnteredHandler on_entered_handler, OnLeftHandler on_left_handler, OnMovedHandler on_moved_handler)
	{
		aoi_manager_->get_aoi_event_system().AddOnEnteredHandler(on_entered_handler);
		aoi_manager_->get_aoi_event_system().AddOnLeftHandler(on_left_handler);
		aoi_manager_->get_aoi_event_system().AddOnMovedHandler(on_moved_handler);

		OnInit();
	}

	void AOIService::OnInit()
	{
		
	}

	aoi::AOIActor* AOIService::Add(const aoi::IAOILocation& actor_location)
	{
		// 由aoi控制器 进行实际的转换工作
		auto aoiRegion = aoi_manager_->GetAOIRegion(actor_location);
		if (aoiRegion == nullptr) {
			// todo 创建该aoi区域
		}

		auto actorCell = aoi_manager_->GetAOICell(aoiRegion, actor_location);
		if (actorCell == nullptr) {
			// todo 创建cell
			aoiRegion->AddCell(actorCell);
		}

		// 创建actor并添加到 区域内
		auto newActor = aoi_manager_->CreateActor();
		newActor->set_guid(aoi_actor_guid_generator_.Next());
		newActor->set_location(actor_location);
		newActor->set_aoi_cell(actorCell);
		actorCell->AddActor(newActor);

		// 开始触发aoi事件
		aoi_manager_->OnAOIActorAdded(aoiRegion, actorCell, newActor);

		return newActor;
	}

	void AOIService::Remove(const aoi::GUID& actor_guid)
	{
		// 查找是否有对应的actor
		auto actor = aoi_manager_->get_aoi_actor(actor_guid);
		if (actor == nullptr)
			return;

		// todo 从列表移除
		auto actorCell = actor->get_aoi_cell();
		if (actorCell == nullptr)
			return;

		actorCell->RemoveActor(actor);

		// 触发aoi事件
		aoi_manager_->OnAOIActorRemoved(actorCell->get_aoi_region(), actorCell, actor);
	}

	void AOIService::Move(const aoi::GUID actor_guid, const aoi::IAOILocation& target_loc)
	{
		// 查找是否有对应的actor
		auto actor = aoi_manager_->get_aoi_actor(actor_guid);
		if (actor == nullptr)
			return;

		// 当前cell
		auto currentCell = actor->get_aoi_cell();
		if (currentCell == nullptr)
			return;

		// 新cell
		auto newCell = aoi_manager_->GetAOICell(currentCell->get_aoi_region(), target_loc);
		if (newCell == nullptr)
			return;

		// 离开了aoi范围的cells
		std::vector<aoi::AOIActorCell*> exited_cells;
		// 仍然在aoi范围内的cells
		std::vector<aoi::AOIActorCell*> remain_cells;
		// 新进入到aoi范围内的cells
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
				aoi_manager_->OnAOIActorRemoved(*actor_iter, actor);
				aoi_manager_->OnAOIActorRemoved(actor, *actor_iter);
			}
		}

		for (auto cell : entered_cells) {
			auto actor_iter = cell->get_actor_iter_begin();
			auto actor_iter_end = cell->get_actor_iter_end();

			for (; actor_iter != actor_iter_end; ++actor_iter) {
				aoi_manager_->OnAOIActorAdded(*actor_iter, actor);
				aoi_manager_->OnAOIActorAdded(actor, *actor_iter);
			}
		}

		for (auto cell : remain_cells) {
			auto actor_iter = cell->get_actor_iter_begin();
			auto actor_iter_end = cell->get_actor_iter_end();

			for (; actor_iter != actor_iter_end; ++actor_iter) {
				aoi_manager_->OnAOIActorMoved(*actor_iter, actor);
				aoi_manager_->OnAOIActorMoved(actor, *actor_iter);
			}
		}
	}

}