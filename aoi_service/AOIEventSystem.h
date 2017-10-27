/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 17:17
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOIEVENTSYSTEM_H__
#define __AOI_SERVICE_AOIEVENTSYSTEM_H__

#include <vector>
#include "AOIEvent.h"
#include "AOIActor.h"

namespace aoi
{
	class AOIEventSystem
	{
	private:
	//////////////////////////////////////////////////////////////////////////
	// �����������
		std::vector<OnEnteredHandler> OnEnteredHandlers;
		std::vector<OnLeftHandler> OnLeftHandlers;
		std::vector<OnMovedHandler> onMOvedHandlers;
		
	public:
	//////////////////////////////////////////////////////////////////////////
	// �������get/set
		void AddOnEnteredHandler(OnEnteredHandler handler) {
			this->onMOvedHandlers.push_back(handler);
		}

		void AddOnLeftHandler(OnLeftHandler handler) {
			this->OnLeftHandlers.push_back(handler);
		}

		void AddOnMovedHandler(OnMovedHandler handler) {
			this->onMOvedHandlers.push_back(handler);
		}
		
	//////////////////////////////////////////////////////////////////////////
	// �������
	public:
		void OnActorEntered(aoi::AOIActor* watcher, aoi::AOIActor* target);
		void OnActorLeft(aoi::AOIActor* watcher, aoi::AOIActor* target);
		void OnActorMoved(aoi::AOIActor* watcher, aoi::AOIActor* target);

	protected:
	private:
	};
}

#endif  // __AOI_SERVICE_AOIEVENTSYSTEM_H__
