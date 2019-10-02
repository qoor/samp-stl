#pragma once

template <typename T>
class CContainer
{
private:
	std::vector<T*> m_containers;
	CIdentifier m_identifier;

public:
	T* GetContainer(cell id) const;

	size_t size() const { return m_containers.size(); }
};

template <typename T>
class CContainerManager
{
	friend class CContainer<T>

private:
	std::unordered_map<AMX*, CContainer<T>> m_containerLists;

public:
	CContainer<T>* GetContainerList(AMX* pAmx);

	cell CreateContainer(AMX* pAmx);
	bool DeleteContainer(AMX* pAmx, cell id);
	//T* GetContainer(AMX* pAmx, cell id) const;
};
