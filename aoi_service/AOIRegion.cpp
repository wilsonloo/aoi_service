/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 16:21
 * Description : 
*********************************************************************/

#include "AOIRegion.h"

#include "AOIActor.h"
#include "AOIActorCell.h"

namespace aoi
{

	void AOIRegion::AddActorCell(AOIActorCell* cell)
	{
		//
		throw std::logic_error("The method or operation is not implemented.");
	}

	void AOIRegion::RemoveActorCell(AOIActorCell* cell)
	{
		//
		throw std::logic_error("The method or operation is not implemented.");
	}

	void AOIRegion::AddCell(AOIActorCell* actor_cell)
	{
		// todo 
	}

	void AOIRegion::Foreach(ForeachActorFunctor functor)
	{
		//
		throw std::logic_error("The method or operation is not implemented.");
	}

	void AOIRegion::Foreach(ForeachActorCellFunctor functor)
	{
		//
		throw std::logic_error("The method or operation is not implemented.");
	}

}

