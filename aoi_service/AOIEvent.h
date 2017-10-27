/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 12:24
 * Description : AOI ʱ�䴦��
*********************************************************************/

#ifndef __AOI_SERVICE_AOIEVENT_H__
#define __AOI_SERVICE_AOIEVENT_H__

#include <functional>

namespace aoi
{
	class AOIActor;

	/************************************************************************
	* Ŀ������¼�
	@watcher �۲���
	@marker  ���۲���
	/************************************************************************/
	typedef std::function<void(AOIActor& watcher, AOIActor target)> OnEnteredHandler;

	/************************************************************************
	* Ŀ���뿪�¼�
	@watcher �۲���
	@marker  ���۲���
	/************************************************************************/
	typedef std::function<void(AOIActor& watcher, AOIActor marker)> OnLeftHandler;

	/************************************************************************
	* Ŀ���ƶ��¼�
	@watcher �۲���
	@marker  ���۲���
	/************************************************************************/
	typedef std::function<void(AOIActor& watcher, AOIActor marker)> OnMovedHandler;

}

#endif  // __AOI_SERVICE_AOIEVENT_H__
