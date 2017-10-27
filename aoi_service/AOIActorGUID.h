/********************************************************************
 *     Author  : Wensheng.Luo
 *       Mail  : samule21@163.com
 * CreateTime  : 2017-10-18 15:58
 * Description : 
*********************************************************************/

#ifndef __AOI_SERVICE_AOIACTORGUID_H__
#define __AOI_SERVICE_AOIACTORGUID_H__

namespace aoi
{
	struct GUID
	{
		unsigned __int64 uid;

		bool Equal(const GUID& other) const {
			return this->uid == other.uid;
		}

		bool Equal(const GUID* other) const {
			return this->uid == other->uid;
		}
	};

	class AOIActorGUIDGenerator
	{
	private:
	//////////////////////////////////////////////////////////////////////////
	// 数据相关声明
		unsigned __int64 uid_ = 0;
		
	public:
	//////////////////////////////////////////////////////////////////////////
	// 数据相关get/set
		
	//////////////////////////////////////////////////////////////////////////
	// 方法相关
	public:
		GUID Next() {
			GUID guid;
			guid.uid = (++uid_);

			return guid;
		}

	protected:
	private:
	};

	struct GUIDComparatorType
	{
		bool operator()(const GUID& a, const GUID& b) const{
			return a.Equal(b);
		}

		bool operator()(const GUID* a, const GUID* b) const {
			return a->Equal(b);
		}
	};
}

#endif  // __AOI_SERVICE_AOIACTORGUID_H__
