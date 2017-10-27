#include <Windows.h>                  // 包含 HINSTANCE
#include <iostream>
#include "../aoi_service/IAOIService.h"
#include "../aoi_service/AOIActor.h"
#include "grid_impl/AOIManagerGridImpl.h"
#include "Location.h"

/************************************************************************
* 目标进入事件
@watcher 观察者
@marker  被观察者
/************************************************************************/
void OnEnteredHandler(aoi::AOIActor& watcher, aoi::AOIActor target) {
	throw std::logic_error("The method or operation is not implemented.");
}

/************************************************************************
* 目标离开事件
@watcher 观察者
@marker  被观察者
/************************************************************************/
void OnLeftHandler(aoi::AOIActor& watcher, aoi::AOIActor target) {
	throw std::logic_error("The method or operation is not implemented.");
}

/************************************************************************
* 目标移动事件
@watcher 观察者
@marker  被观察者
/************************************************************************/
void OnMovedHandler(aoi::AOIActor& watcher, aoi::AOIActor target) {
	throw std::logic_error("The method or operation is not implemented.");
}

int main()
{
	HINSTANCE his = LoadLibraryA("G:\\aoi_service\\x64\\Debug\\aoi_service.dll");                    //用于加载dll

	typedef aoi::IAOIService*(*AOIServiceCreateFunctor)();
	auto create_functor = (AOIServiceCreateFunctor)GetProcAddress(his, "CreateAOIService");                  //GetProcAddress()用于获得函数地址
	aoi::IAOIService* service = create_functor();
	std::cout << service->GetVersion() << std::endl;

	// 初始化
	auto aoi_manager = new AOIManagerGridImpl();
	aoi_manager->Init(10, 10, 100, 100);
	service->Init(aoi_manager, OnEnteredHandler, OnLeftHandler, OnMovedHandler);

	// 增加一个位置
	Location pos;
	pos.x = 100;
	pos.y = 100;

	auto newActor = service->Add(pos);

	aoi::GUID uid;
	service->Remove(uid);

	FreeLibrary(his);                                                   //释放dll
	system("pause");

	return 0;
}
