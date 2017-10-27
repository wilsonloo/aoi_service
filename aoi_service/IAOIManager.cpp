/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 17:07
 * Description : 
*********************************************************************/

#include "IAOIManager.h"

#include "AOIActor.h"
#include "AOIActorCell.h"
#include "AOIRegion.h"

namespace aoi
{
	void IAOIManager::OnAOIActorAdded(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, aoi::AOIActor* new_aoi_actor)
	{
		// todo 其他如统计相关处理

		ForeachAOIActorInRange(aoi_region, aoi_cell, [&](aoi::AOIActor* actor) {
			// 忽略自身
			if (actor == new_aoi_actor)
				return;

			OnAOIActorAdded(new_aoi_actor, actor);
			OnAOIActorAdded(actor, new_aoi_actor);
		});
	}

	void IAOIManager::OnAOIActorAdded(aoi::AOIActor* watcher, aoi::AOIActor* target)
	{
		aoi_event_system.OnActorEntered(watcher, target);
	}

	void IAOIManager::OnAOIActorRemoved(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, aoi::AOIActor* removed_aoi_actor)
	{
		// 从映射列表移除
		RemoveActor(removed_aoi_actor);

		// 如果cell为空，则回收
		if (aoi_cell->IsEmpty()) {
			aoi_region->RemoveActorCell(aoi_cell);
		}

		ForeachAOIActorInRange(aoi_region, aoi_cell, [&](aoi::AOIActor* actor) {

			OnAOIActorRemoved(removed_aoi_actor, actor);
			OnAOIActorRemoved(actor, removed_aoi_actor);
		});
	}

	void IAOIManager::OnAOIActorRemoved(aoi::AOIActor* watcher, aoi::AOIActor* target)
	{
		aoi_event_system.OnActorLeft(watcher, target);
	}

	void IAOIManager::OnAOIActorMoved(aoi::AOIActor* watcher, aoi::AOIActor* target)
	{
		aoi_event_system.OnActorMoved(watcher, target);
	}

}