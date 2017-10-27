/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 11:49
 * Description : AOI ≤Œ”Î’ﬂ
*********************************************************************/

#ifndef __AOI_SERVICE_AOIACTOR_H__
#define __AOI_SERVICE_AOIACTOR_H__

#include <memory>
#include "AOIActorGUID.h"
#include "IAOILocation.h"

namespace aoi
{
	class AOIActorCell;

	class AOIActor
	{
	private:
		GUID guid_;
		AOIActorCell* aoi_cell_;

	public:

		inline const GUID& get_guid() const { return guid_; }
		inline void set_guid(const GUID& val) { guid_ = val; }

		inline aoi::AOIActorCell* get_aoi_cell() const { return aoi_cell_; }
		inline void set_aoi_cell(aoi::AOIActorCell* val) { aoi_cell_ = val; }

	public:
		virtual ~AOIActor(){}

	public:
		bool IsEqual(const aoi::AOIActor& other) const {
			return other.get_guid().Equal(this->get_guid());
		}

	}; // class AOIActor
}

#endif  // __AOI_SERVICE_AOIACTOR_H__