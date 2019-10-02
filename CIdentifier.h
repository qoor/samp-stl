#pragma once

class CIdentifier
{
private:
	std::priority_queue<cell, std::vector<int>, std::greater<int>> m_removeIds;
	cell m_lastId;

public:
	CIdentifier() : m_lastId(0) { }

	cell Get();
	void Remove(cell id);
	void Clear();
};
