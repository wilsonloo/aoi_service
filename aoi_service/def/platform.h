/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-26 18:10
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_DEF_PLATFORM_H__
#define __AOI_SERVICE_DEF_PLATFORM_H__

//////////////////////////////////////////////////////////////////////////
// 平台枚举
#define NF_PLATFORM_WIN 1
#define NF_PLATFORM_LINUX 2
#define NF_PLATFORM_APPLE 3
#define NF_PLATFORM_SYMBIAN 4
#define NF_PLATFORM_APPLE_IOS 5
#define NF_PLATFORM_ANDROID 6

//////////////////////////////////////////////////////////////////////////
// 确定平台
#if defined( __WIN32__ ) || defined( _WIN32 ) || defined(_WINDOWS) || defined(WIN) || defined(_WIN64) || defined( __WIN64__ )
#define NF_PLATFORM NF_PLATFORM_WIN
#endif // 确定平台

//----------------------------------------------------------------------------
// Windows Settings
#if NF_PLATFORM == NF_PLATFORM_WIN

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif

#else
#define OPERA_LIB_API 

#endif // // Windows Settings

#endif  // __AOI_SERVICE_DEF_PLATFORM_H__
