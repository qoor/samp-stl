#include "StdInc.h"
#include "CVector.h"

template <typename T>
T* CContainer<T>::GetContainer(cell id) const
{
	if (id < m_containers.size())
		return m_containers[id];

	return nullptr;
}

template <typename T>
CContainer<T>* CContainerManager<T>::GetContainerList(AMX* pAmx)
{
	std::unordered_map<AMX*, CVector>::iterator it =
		ms_vectors.find(pAmx);

	if (it != ms_vectors.end())
		return &(it->second);

	return nullptr;
}

template <typename T>
cell CContainerManager<T>::CreateContainer(AMX* pAmx)
{
	CContainer<T>* pContainerList = GetContainerList(pAmx);

	if (pContainerList)
	{
		cell id = pContainerList->m_identifier.Get();

		if (id < pContainerList->size())
			pContainerList->m_containers[id] = new T();
		else
			pContainerList->m_containers.push_back(new T());

		return id;
	}

	return 0;
}

template <typename T>
bool CContainerManager<T>::DeleteContainer(AMX* pAmx, cell id)
{
	CContainer<T>* pContainerList = GetContainerList(pAmx);

	if (!pContainerList)
		return false;

	T* pContainer = pContainerList->GetContainer(id);

	if (pContainer)
	{
		delete pContainerList->m_containers[id];
		pContainerList->m_containers[id] = nullptr;
		pContainerList->m_identifier.Remove(id);
		return true;
	}

	return false;
}

/*template <typename T>
T* CContainerManager<T>::GetContainer(AMX* pAmx, cell id) const
{

}*/
