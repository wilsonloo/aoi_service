/********************************************************************
*     Author  : Wensheng.Luo
*       Mail  : samule21@163.com
* CreateTime  : 2017-10-18 15:45
* Description :
*********************************************************************/

#ifndef __AOI_SERVICE_AOI_MANAGER_GRID_IMPL_H__
#define __AOI_SERVICE_AOI_MANAGER_GRID_IMPL_H__

#include "../aoi_service/IAOIManager.h"

class AOIManagerGridImpl : public aoi::IAOIManager
{
public:
	enum
	{
		INVALID_REGION_IDX = 0xffffFFFF,
	};

	typedef std::map<int/*region-id*/, aoi::AOIRegion*> AOIRegionMapType;

private:
	int cell_width_;
	int cell_hight_;
	int map_width_;
	int map_hight_;

	int rows_;
	int cols_;

	AOIRegionMapType regions_;

public:


	inline int get_cell_width() const { return cell_width_; }
	inline void set_cell_width(int val) { cell_width_ = val; }

	inline int get_cell_hight() const { return cell_hight_; }
	inline void set_cell_hight(int val) { cell_hight_ = val; }

	inline int get_map_width() const { return map_width_; }
	inline void set_map_width(int val) { map_width_ = val; }

	inline int get_map_hight() const { return map_hight_; }
	inline void set_map_hight(int val) { map_hight_ = val; }

	inline int get_rows() const { return rows_; }
	inline void set_rows(int val) { rows_ = val; }

	inline int get_cols() const { return cols_; }
	inline void set_cols(int val) { cols_ = val; }

public:
	void Init(int cell_width, int cell_hight, int map_width, int map_hight);
	
	int GetRegionIndex(int x, int y);

	virtual bool DiffActerCellsOnAOIRange(const aoi::AOIActorCell* aoi_cell_1, 
		const aoi::AOIActorCell* aoi_cell_2, 
		const int aoi_range, 
		std::vector<aoi::AOIActorCell*>& exited_cells, 
		std::vector<aoi::AOIActorCell*>& remain_cells, 
		std::vector<aoi::AOIActorCell*>& entered_cells) override;

	virtual aoi::AOIActor* CreateActor() override;

	virtual aoi::AOIRegion* GetAOIRegion(const aoi::IAOILocation& actor_location) override;

	virtual aoi::AOIActorCell* GetAOICell(const aoi::IAOILocation& actor_location) override;

	virtual aoi::AOIActorCell* GetAOICell(aoi::AOIRegion* region, const aoi::IAOILocation& actor_location) override;

	virtual void ForeachAOIActorInRange(aoi::AOIRegion* aoi_region, aoi::AOIActorCell* aoi_cell, std::function<void(aoi::AOIActor*) > callback) override;

	virtual void AddActor(aoi::AOIActor* actor) override;

	virtual void RemoveActor(aoi::AOIActor* actor) override;

};

#endif // __AOI_SERVICE_AOI_MANAGER_GRID_IMPL_H__