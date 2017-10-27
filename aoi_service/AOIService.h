/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 14:24
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOISERVICE_H__
#define __AOI_SERVICE_AOISERVICE_H__

#include "IAOIService.h"
#include "AOIEvent.h"
#include "AOIActorGUID.h"
#include "AOIEventSystem.h"

namespace aoi
{
	struct GUID;
	class AOIActor;
	class AOIActorCell;
	class AOIRegion;
	class IAOILocation;
	class AOIControl;
	class IAOIManager;

    class AOIService : public IAOIService
    {
	//////////////////////////////////////////////////////////////////////////
	// 数据相关get/set
	private:

		AOIEventSystem aoi_event_system;
		IAOIManager* aoi_manager_ = nullptr;
		AOIActorGUIDGenerator aoi_actor_guid_generator_;
		int aoi_range_ = 10;

	//////////////////////////////////////////////////////////////////////////
	// 数据相关get/set
	public:

		inline IAOIManager* get_aoi_manager() const { return aoi_manager_; }
		inline void set_aoi_manager(IAOIManager* val) { aoi_manager_ = val; }

		inline AOIActorGUIDGenerator& get_aoi_actor_guid_generator() { return aoi_actor_guid_generator_; }

		virtual int get_aoi_range() const { return aoi_range_; }
		virtual void set_aoi_range(int val) { aoi_range_ = val; }

	//////////////////////////////////////////////////////////////////////////
	// 方法相关
	public:
		virtual int GetVersion() override { return 999;  }

		virtual void Init(aoi::IAOIManager* aoi_manager, 
			aoi::OnEnteredHandler on_entered_handler,
			aoi::OnLeftHandler on_left_handler,
			aoi::OnMovedHandler on_moved_handler);

		virtual aoi::AOIActor* Add(const aoi::IAOILocation& actor_location);
		virtual void Remove(const aoi::GUID& actor_guid);
		virtual void Move(const aoi::GUID actor_guid, const aoi::IAOILocation& target_loc);

	protected:
		virtual void OnInit();
		void OnAOIActorAdded(aoi::AOIRegion * aoi_region, aoi::AOIActorCell * aoi_cell, aoi::AOIActor * new_aoi_actor);
		void OnAOIActorRemoved(aoi::AOIRegion * aoi_region, aoi::AOIActorCell * aoi_cell, aoi::AOIActor * removed_aoi_actor);



    }; // class AOIService
}

#endif  // __AOI_SERVICE_AOISERVICE_H__
