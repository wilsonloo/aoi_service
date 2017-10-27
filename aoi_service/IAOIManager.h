/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 15:04
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOIMANAGER_H__
#define __AOI_SERVICE_AOIMANAGER_H__

#include <functional>
#include <map>
#include "AOIEventSystem.h"
#include "AOIActorCellPool.h"

namespace aoi
{
	class AOIRegion;

    class IAOIManager
    {
	private:
		AOIActorCellPool aoi_cell_pool_;
		AOIEventSystem aoi_event_system;
		unsigned int aoi_range_;
		
		// aoi-actor 映射表
		typedef std::map < GUID, AOIActor*, GUIDComparatorType > AOIActorMapType;
		AOIActorMapType aoi_actors_;

	public:
		inline aoi::AOIEventSystem& get_aoi_event_system() { return aoi_event_system; }

		inline unsigned int get_aoi_range() const { return aoi_range_; }
		inline void set_aoi_range(unsigned int val) { aoi_range_ = val; }

		inline AOIActor* get_aoi_actor(const GUID& guid) {
			AOIActorMapType::iterator find_iter = aoi_actors_.find(guid);
			return find_iter != aoi_actors_.end() ? find_iter->second : NULL;
		}

	public:

		virtual AOIActor* CreateActor() = 0;

		void AddActor(aoi::AOIActor* actor);
		void RemoveActor(aoi::AOIActor* actor);

		/************************************************************************
		* 根据位置信息获取对应的区域
		/************************************************************************/
		virtual AOIRegion* GetAOIRegion(const aoi::IAOILocation& actor_location) = 0;
		virtual AOIActorCell* GetAOICell(const aoi::IAOILocation& actor_location) = 0;

		/************************************************************************
		 * 在aoi区域内获取指定位置的 cell                                                                 
		/************************************************************************/
		virtual AOIActorCell* GetAOICell(const aoi::AOIRegion* region, const aoi::IAOILocation& actor_location) = 0;

		/************************************************************************
		 *                                                                  
		/************************************************************************/
		virtual bool DiffActerCellsOnAOIRange(const aoi::AOIActorCell* aoi_cell_1, 
			const aoi::AOIActorCell* aoi_cell_2,
			const int aoi_range,
			std::vector<aoi::AOIActorCell*>& exited_cells,
			std::vector<aoi::AOIActorCell*>& remain_cells, 
			std::vector<aoi::AOIActorCell*>& entered_cells) = 0;

		virtual void ForeachAOIActorInRange(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, std::function<void(aoi::AOIActor*)> callback) = 0;

		virtual void OnAOIActorAdded(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, aoi::AOIActor* new_aoi_actor);
		virtual void OnAOIActorAdded(aoi::AOIActor* watcher, aoi::AOIActor* target);

		virtual void OnAOIActorRemoved(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, aoi::AOIActor* removed_aoi_actor);
		virtual void OnAOIActorRemoved(aoi::AOIActor* watcher, aoi::AOIActor* target);

		virtual void OnAOIActorMoved(aoi::AOIActor* watcher, aoi::AOIActor* target);

	}; // class AOIManager
}

#endif  // __AOI_SERVICE_AOIMANAGER_H__
