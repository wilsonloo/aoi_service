/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 14:23
 * Description : aoi 区域（包含多个aoi-actor）
*********************************************************************/

#ifndef __AOI_SERVICE_AOIREGION_H__
#define __AOI_SERVICE_AOIREGION_H__

#include <functional>
#include <memory>

namespace aoi
{
	class IAOILocation;
	class AOIActor;
	class AOIActorCell;

    class AOIRegion
    {
	public:
		enum FOREACH_ACTION_ENUM {
			CONTINUE = 0,
			BREAK,
		};

	public:
		typedef std::function<void(aoi::AOIActor&)> ForeachActorFunctor;
		typedef std::function<void(aoi::AOIActorCell&)> ForeachActorCellFunctor;
		typedef std::function<FOREACH_ACTION_ENUM(aoi::AOIActorCell&)> ForeachActorCellFunctorWithAction;

	public:

		void AddActorCell(aoi::AOIActorCell* cell);
		void RemoveActorCell(aoi::AOIActorCell* cell);
		
		/************************************************************************
		 * 将actor 添加到 指定cell内（一个cell对应一个位置，一个位置上有多个actor）                                                                 
		/************************************************************************/
		void AddCell(aoi::AOIActorCell* actor_cell);

		void Foreach(ForeachActorFunctor functor);
		void Foreach(ForeachActorCellFunctor functor);
		void Foreach(ForeachActorCellFunctorWithAction functor);

    }; // class AOIRegion
}

#endif  // __AOI_SERVICE_AOIREGION_H__
