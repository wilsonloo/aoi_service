/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-27 15:07
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_IAOISERVICE_H__
#define __AOI_SERVICE_IAOISERVICE_H__

#include "def/setup.h"
#include "AOIEvent.h"
#include "IAOILocation.h"
#include "AOIActorGUID.h"

namespace aoi
{
	class IAOIManager;

	class IAOIService
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// 获取版本新信息
		virtual int GetVersion() = 0;

		//////////////////////////////////////////////////////////////////////////
		// 初始化
		virtual void Init(aoi::IAOIManager* aoi_manager, 
			aoi::OnEnteredHandler on_entered_handler,
			aoi::OnLeftHandler on_left_handler,
			aoi::OnMovedHandler on_moved_handler) = 0;

		virtual AOIActor* Add(const aoi::IAOILocation& actor_location) = 0;
		virtual void Remove(const aoi::GUID& actor_guid) = 0;
		virtual void Move(const aoi::GUID actor_guid, const aoi::IAOILocation& target_loc) = 0;

		virtual int get_aoi_range() const = 0;
		virtual void set_aoi_range(int val) = 0;

	protected:
		virtual void OnInit() = 0;
	};
}

extern "C" OPERA_LIB_API aoi::IAOIService* CreateAOIService();
extern "C" OPERA_LIB_API void ReleaseAOIService(aoi::IAOIService* obj);


#endif  // __AOI_SERVICE_IAOISERVICE_H__
