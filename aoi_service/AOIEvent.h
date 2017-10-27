/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 12:24
 * Description : AOI 时间处理
*********************************************************************/

#ifndef __AOI_SERVICE_AOIEVENT_H__
#define __AOI_SERVICE_AOIEVENT_H__

#include <functional>

namespace aoi
{
	class AOIActor;

	/************************************************************************
	* 目标进入事件
	@watcher 观察者
	@marker  被观察者
	/************************************************************************/
	typedef std::function<void(AOIActor& watcher, AOIActor target)> OnEnteredHandler;

	/************************************************************************
	* 目标离开事件
	@watcher 观察者
	@marker  被观察者
	/************************************************************************/
	typedef std::function<void(AOIActor& watcher, AOIActor marker)> OnLeftHandler;

	/************************************************************************
	* 目标移动事件
	@watcher 观察者
	@marker  被观察者
	/************************************************************************/
	typedef std::function<void(AOIActor& watcher, AOIActor marker)> OnMovedHandler;

}

#endif  // __AOI_SERVICE_AOIEVENT_H__
