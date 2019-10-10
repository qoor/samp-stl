#pragma once

template <typename T>
class CSingleton
{
private:
	static T* ms_pObject;

protected:
	CSingleton()
	{
		assert(ms_pObject == nullptr);
	}
};
