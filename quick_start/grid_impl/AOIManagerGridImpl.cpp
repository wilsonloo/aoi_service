/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-26 12:15
 * Description : 
*********************************************************************/

#include "AOIManagerGridImpl.h"
#include <cassert>
#include "../aoi_service/AOIRegion.h"
#include "../aoi_service/AOIActorCell.h"
#include "Location.h"

bool AOIManagerGridImpl::DiffActerCellsOnAOIRange(const aoi::AOIActorCell* aoi_cell_1, const aoi::AOIActorCell* aoi_cell_2, const int aoi_range, std::vector<aoi::AOIActorCell*>& exited_cells, std::vector<aoi::AOIActorCell*>& remain_cells, std::vector<aoi::AOIActorCell*>& entered_cells)
{
	//
	throw std::logic_error("The method or operation is not implemented.");
}

aoi::AOIActor* AOIManagerGridImpl::CreateActor()
{
	// throw std::logic_error("The method or operation is not implemented.");
	throw std::logic_error("The method or operation is not implemented.");
}

aoi::AOIRegion* AOIManagerGridImpl::GetAOIRegion(const aoi::IAOILocation& actor_location)
{
	auto pos = static_cast<const Location&>(actor_location);
	int region_idx = GetRegionIndex(pos.x, pos.y);
	
	AOIRegionMapType::iterator iter = regions_.find(region_idx);
	return iter != regions_.end() ? iter->second : nullptr;
}

aoi::AOIActorCell* AOIManagerGridImpl::GetAOICell(const aoi::IAOILocation& actor_location)
{
	// throw std::logic_error("The method or operation is not implemented.");
	throw std::logic_error("The method or operation is not implemented.");
}

aoi::AOIActorCell* AOIManagerGridImpl::GetAOICell(aoi::AOIRegion* region, const aoi::IAOILocation& actor_location)
{
	auto pos = static_cast<const Location&>(actor_location);

	aoi::AOIActorCell* found_cell = nullptr;

	// µü´úÆ÷
	aoi::AOIRegion::ForeachActorCellFunctorWithAction functor = [&](aoi::AOIActorCell& cell) {
		auto actor_pos = static_cast<const Location&>(cell.get_location());
		if (actor_pos.IsEqual(pos)) {
			found_cell = &cell;
			return aoi::AOIRegion::FOREACH_ACTION_ENUM::BREAK;
		}

		return aoi::AOIRegion::FOREACH_ACTION_ENUM::CONTINUE;
	};

	region->Foreach(functor);

	return found_cell;
}

void AOIManagerGridImpl::ForeachAOIActorInRange(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, std::function<void(aoi::AOIActor*) > callback)
{
	// throw std::logic_error("The method or operation is not implemented.");
	throw std::logic_error("The method or operation is not implemented.");
}

void AOIManagerGridImpl::AddActor(aoi::AOIActor* actor)
{
	// throw std::logic_error("The method or operation is not implemented.");
	throw std::logic_error("The method or operation is not implemented.");
}

void AOIManagerGridImpl::RemoveActor(aoi::AOIActor* actor)
{
	// throw std::logic_error("The method or operation is not implemented.");
	throw std::logic_error("The method or operation is not implemented.");
}

void AOIManagerGridImpl::Init(int cell_width, int cell_hight, int map_width, int map_hight)
{
	assert(cell_width > 0);
	assert(cell_hight > 0);
	assert(map_width > 0);
	assert(map_hight > 0);

	set_cell_width(cell_width);
	set_cell_hight(cell_hight);
	set_map_width(map_width);
	set_map_hight(map_hight);

    set_cols(std::ceil(map_width * 1.0 / cell_width));
	set_rows(std::ceil(map_hight * 1.0 / cell_hight));
}

int AOIManagerGridImpl::GetRegionIndex(int x, int y)
{
	if (x < 0 || y < 0)
		return INVALID_REGION_IDX;

	int x_count = x / get_cell_width();
	int y_count = y / get_cell_hight();

	return y_count * get_cols() + x_count;
}

