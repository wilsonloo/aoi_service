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
	// �����������
		
	public:
	//////////////////////////////////////////////////////////////////////////
	// �������get/set
		
	//////////////////////////////////////////////////////////////////////////
	// �������
	public:
		AOIActorCell* CreateAOICell();
		void Release(AOIActorCell* releasingCell);

	protected:
	private:
	};
}

#endif  // __AOI_SERVICE_AOIACTORCELLPOOL_H__
