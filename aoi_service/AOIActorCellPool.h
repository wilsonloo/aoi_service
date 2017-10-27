/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 18:47
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOIACTORCELLPOOL_H__
#define __AOI_SERVICE_AOIACTORCELLPOOL_H__

namespace aoi
{
	class AOIActorCell;

	class AOIActorCellPool
	{
	private:
	//////////////////////////////////////////////////////////////////////////
	// 数据相关声明
		
	public:
	//////////////////////////////////////////////////////////////////////////
	// 数据相关get/set
		
	//////////////////////////////////////////////////////////////////////////
	// 方法相关
	public:
		AOIActorCell* CreateAOICell();
		void Release(AOIActorCell* releasingCell);

	protected:
	private:
	};
}

#endif  // __AOI_SERVICE_AOIACTORCELLPOOL_H__
