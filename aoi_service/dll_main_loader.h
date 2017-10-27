/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-26 18:17
 * Description : dll ¼ÓÔØ
*********************************************************************/

#ifndef __AOI_SERVICE_DLL_MAIN_LOADER_H__
#define __AOI_SERVICE_DLL_MAIN_LOADER_H__

#include "def/platform.h"

//////////////////////////////////////////////////////////////////////////
// ÉùÃ÷¶¯Ì¬¿âºê
#if NF_PLATFORM == NF_PLATFORM_WIN
#    define DYNLIB_HANDLE hInstance
#    define DYNLIB_LOAD( a ) LoadLibraryEx( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#    define DYNLIB_GETSYM( a, b ) GetProcAddress( a, b )
#    define DYNLIB_UNLOAD( a ) FreeLibrary( a )

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#endif // ÉùÃ÷¶¯Ì¬¿âºê

#endif  // __AOI_SERVICE_DLL_MAIN_LOADER_H__
