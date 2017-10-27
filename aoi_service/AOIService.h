/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 14:24
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOISERVICE_H__
#define __AOI_SERVICE_AOISERVICE_H__

#include "AOIEvent.h"
#include "AOIActorGUID.h"

namespace aoi
{
	struct GUID;
	class AOIActor;
	class IAOILocation;
	class AOIControl;
	class IAOIManager;

    class AOIService
    {
	//////////////////////////////////////////////////////////////////////////
	// 数据相关get/set
	private:
		IAOIManager* aoi_manager_ = nullptr;
		AOIActorGUIDGenerator aoi_actor_guid_generator_;
		int aoi_range_ = 10;

	//////////////////////////////////////////////////////////////////////////
	// 数据相关get/set
	public:

		inline IAOIManager* get_aoi_manager() const { return aoi_manager_; }
		inline void set_aoi_manager(IAOIManager* val) { aoi_manager_ = val; }

		inline AOIActorGUIDGenerator& get_aoi_actor_guid_generator() { return aoi_actor_guid_generator_; }

		inline int get_aoi_range() const { return aoi_range_; }
		inline void set_aoi_range(int val) { aoi_range_ = val; }

		//////////////////////////////////////////////////////////////////////////
	// 方法相关
	public:
		void Init(OnEnteredHandler on_entered_handler,
			OnLeftHandler on_left_handler,
			OnMovedHandler on_moved_handler);

	protected:
		virtual void OnInit();

	public:
		AOIActor* Add(const aoi::IAOILocation& actor_location);
		void Remove(const aoi::GUID& actor_guid);
		void Move(const aoi::GUID actor_guid, const aoi::IAOILocation& target_loc);

    }; // class AOIService
}

#endif  // __AOI_SERVICE_AOISERVICE_H__
