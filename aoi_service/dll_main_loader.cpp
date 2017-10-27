/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-26 18:18
 * Description : 
*********************************************************************/

#include "dll_main_loader.h"
#include <iostream>

#ifdef OPERA_DYNAMIC_EXPORT

OPERA_EXPORT void DllStartPlugin()
{
	std::string strLibPath = "./aio_service";
	DYNLIB_HANDLE instance = (DYNLIB_HANDLE)DYNLIB_LOAD(strLibPath.c_str());

	return instance != NULL;
};

OPERA_EXPORT void DllStopPlugin()
{
	
};

#endif

