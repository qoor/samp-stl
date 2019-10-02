#include "StdInc.h"

cell CIdentifier::Get()
{
	cell id;

	if (m_removeIds.size())
	{
		id = m_removeIds.top();
		m_removeIds.pop();
	}
	else
		id = ++m_lastId;

	return id;
}

void CIdentifier::Remove(cell id)
{
	m_removeIds.push(id);
}

void CIdentifier::Clear()
{
	m_lastId = 0;
	m_removeIds = std::priority_queue<cell, std::vector<int>, std::greater<int>>();
}
