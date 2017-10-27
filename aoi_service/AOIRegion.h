/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 14:23
 * Description : aoi ���򣨰������aoi-actor��
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
		typedef std::function<void(AOIActor&)> ForeachFunctor;

	public:

		void AddActorCell(AOIActorCell* cell);
		void RemoveActorCell(AOIActorCell* cell);
		
		/************************************************************************
		 * ��actor ��ӵ� ָ��cell�ڣ�һ��cell��Ӧһ��λ�ã�һ��λ�����ж��actor��                                                                 
		/************************************************************************/
		void AddCell(AOIActorCell* actor_cell);

		void Foreach(ForeachFunctor functor);

    }; // class AOIRegion
}

#endif  // __AOI_SERVICE_AOIREGION_H__
