/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 15:45
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOIACTORLIST_H__
#define __AOI_SERVICE_AOIACTORLIST_H__

#include <list>
#include <memory>

namespace aoi
{
	struct GUID;
	class AOIActor;
	class AOIRegion;

    class AOIActorCell
    {
	private:
		AOIRegion* aoi_region_;
		std::list<AOIActor*> aoi_actors_;

	public:
		inline aoi::AOIRegion* get_aoi_region() const { return aoi_region_; }
		inline void set_aoi_region(aoi::AOIRegion* val) { aoi_region_ = val; }

		inline std::list<AOIActor*>::iterator get_actor_iter_begin() { return aoi_actors_.begin(); }
		inline std::list<AOIActor*>::iterator get_actor_iter_end() { return aoi_actors_.end(); }

	public:
		bool IsEmpty();

		AOIActor* GetActor(const aoi::GUID& actor_guid);
		void RemoveActor(AOIActor* actor);
		void AddActor(AOIActor* actor);

	}; // class AOIActorList
}

#endif  // __AOI_SERVICE_AOIACTORLIST_H__
