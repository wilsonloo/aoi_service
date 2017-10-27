/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 14:51
 * Description : 未实现的异常
*********************************************************************/

#ifndef __AOI_SERVICE_NOTIMPLEMENTEXCEPTION_H__
#define __AOI_SERVICE_NOTIMPLEMENTEXCEPTION_H__

#include <exception>

namespace aoi
{
    class NotImplementException : public std::exception
	{
	public:
		NotImplementException()
			throw()
			: std::exception("this unit not yet be implemented") 
		{

		}

		NotImplementException(const char* message)
			throw()
			: std::exception(message) 
		{

		}
    }; // class NotImplementException
}

#endif  // __AOI_SERVICE_NOTIMPLEMENTEXCEPTION_H__
