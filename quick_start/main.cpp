#include <Windows.h>                  // ���� HINSTANCE
#include <iostream>
#include "../aoi_service/IAOIService.h"
#include "../aoi_service/AOIActor.h"
#include "grid_impl/AOIManagerGridImpl.h"
#include "Location.h"

/************************************************************************
* Ŀ������¼�
@watcher �۲���
@marker  ���۲���
/************************************************************************/
void OnEnteredHandler(aoi::AOIActor& watcher, aoi::AOIActor target) {
	throw std::logic_error("The method or operation is not implemented.");
}

/************************************************************************
* Ŀ���뿪�¼�
@watcher �۲���
@marker  ���۲���
/************************************************************************/
void OnLeftHandler(aoi::AOIActor& watcher, aoi::AOIActor target) {
	throw std::logic_error("The method or operation is not implemented.");
}

/************************************************************************
* Ŀ���ƶ��¼�
@watcher �۲���
@marker  ���۲���
/************************************************************************/
void OnMovedHandler(aoi::AOIActor& watcher, aoi::AOIActor target) {
	throw std::logic_error("The method or operation is not implemented.");
}

int main()
{
	HINSTANCE his = LoadLibraryA("G:\\aoi_service\\x64\\Debug\\aoi_service.dll");                    //���ڼ���dll

	typedef aoi::IAOIService*(*AOIServiceCreateFunctor)();
	auto create_functor = (AOIServiceCreateFunctor)GetProcAddress(his, "CreateAOIService");                  //GetProcAddress()���ڻ�ú�����ַ
	aoi::IAOIService* service = create_functor();
	std::cout << service->GetVersion() << std::endl;

	// ��ʼ��
	auto aoi_manager = new AOIManagerGridImpl();
	aoi_manager->Init(10, 10, 100, 100);
	service->Init(aoi_manager, OnEnteredHandler, OnLeftHandler, OnMovedHandler);

	// ����һ��λ��
	Location pos;
	pos.x = 100;
	pos.y = 100;

	auto newActor = service->Add(pos);

	aoi::GUID uid;
	service->Remove(uid);

	FreeLibrary(his);                                                   //�ͷ�dll
	system("pause");

	return 0;
}
