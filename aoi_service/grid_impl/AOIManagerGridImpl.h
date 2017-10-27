/********************************************************************
*     Author  : Wensheng.Luo
*       Mail  : samule21@163.com
* CreateTime  : 2017-10-18 15:45
* Description :
*********************************************************************/

#ifndef __AOI_SERVICE_AOI_MANAGER_GRID_IMPL_H__
#define __AOI_SERVICE_AOI_MANAGER_GRID_IMPL_H__

#include "IAOIManager.h"

namespace aoi
{
	class AOIManagerGridImpl : public IAOIManager
	{
		virtual bool DiffActerCellsOnAOIRange(const aoi::AOIActorCell* aoi_cell_1, 
			const aoi::AOIActorCell* aoi_cell_2, 
			const int aoi_range, 
			std::vector<aoi::AOIActorCell*>& exited_cells, 
			std::vector<aoi::AOIActorCell*>& remain_cells, 
			std::vector<aoi::AOIActorCell*>& entered_cells) override;
	};
}

#endif // __AOI_SERVICE_AOI_MANAGER_GRID_IMPL_H__