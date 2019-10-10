#pragma once

template <typename T>
class CContainer
{
private:
	std::unordered_map<cell, T> m_containers;
	CIdentifier m_identifier;

public:
	cell AddContainer(size_t size);
	bool RemoveContainer(cell id);
	bool GetContainer(T** destination, cell Id);
};

template <typename T>
class CContainerManager
{
private:
	std::unordered_map<AMX*, CContainer<T>> m_amxContainer;

public:
	void CreateAmxContainer(AMX* pAmx);
	void DeleteAmxContainer(AMX* pAmx);
	bool GetAmxContainer(CContainer<T>** destination, AMX* pAmx);
};
