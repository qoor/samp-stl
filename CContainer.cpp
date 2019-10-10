#include "StdInc.h"

template <typename T>
cell CContainer<T>::AddContainer(size_t size)
{
	cell id = m_identifier.Get();

	if (size == -1)
	{
		m_containers.insert(std::pair<cell, T>(id, T()));
	}
	else
	{
		m_containers.insert(std::pair<cell, T>(id, T(size)));
	}

	return id;
}

template <typename T>
bool CContainer<T>::RemoveContainer(cell id)
{
	return m_containers.erase(id);
}

template <typename T>
bool CContainer<T>::GetContainer(T** destination, cell id)
{
	assert(destination != nullptr);
	std::unordered_map<cell, T>::iterator it = m_containers.find(id);

	if (it != m_containers.end())
	{
		*destination = &(it->second);
		return true;
	}
	
	return false;
}

template <typename T>
void CContainerManager<T>::CreateAmxContainer(AMX* pAmx)
{
	assert(m_amxContainer.find(pAmx) == m_amxContainer.end());
	m_amxContainer.insert(pAmx, CContainer<T>());
}

template <typename T>
void CContainerManager<T>::DeleteAmxContainer(AMX* pAmx)
{
	assert(m_amxContainer.erase(pAmx));
}

template <typename T>
bool CContainerManager<T>::GetAmxContainer(CContainer<T>** destination, AMX* pAmx)
{
	assert(destination != nullptr);
	std::unordered_map<cell, CContainer<T>>::iterator it = m_amxContainer.find(id);

	if (it != m_amxContainer.end())
	{
		*destination = &(it->second);
		return true;
	}

	return false;
}
