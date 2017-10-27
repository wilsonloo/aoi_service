/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-27 17:15
 * Description : 
*********************************************************************/

#ifndef __QUICK_START_LOCATION_H__
#define __QUICK_START_LOCATION_H__

#include "../aoi_service/IAOILocation.h"

class Location : public aoi::IAOILocation{
public:
	int x;
	int y;

public:
	bool IsEqual(const Location& other) {
		return other.x == this->x &&
			other.y == this->y;
	}
};

#endif  // __QUICK_START_LOCATION_H__class Location : public aoi::IAOILocation

