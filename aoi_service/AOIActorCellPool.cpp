/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 18:58
 * Description : 
*********************************************************************/

#include "AOIActorCellPool.h"
#include "AOIActorCell.h"

namespace aoi
{
    
	AOIActorCell* AOIActorCellPool::CreateAOICell()
	{
		auto cellPtr = new AOIActorCell();
		return cellPtr;
	}
}

