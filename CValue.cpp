#include "StdInc.h"

CValue::CValue(eValueType valueType, cell value, cell valueSize)
{
	m_valueType = valueType;
	m_valueSize = valueSize;

	if (valueType == ARRAY)
	{
		cell* pPointer = reinterpret_cast<cell*>(value);

		m_pValue = new cell[valueSize];
		std::copy(pPointer, pPointer + valueSize, m_pValue);
	}
	else
		m_pValue = reinterpret_cast<cell*>(value);
}

CValue::~CValue()
{
	if (m_valueType == ARRAY)
	{
		assert(m_pValue != nullptr);

		delete m_pValue;
		m_pValue = nullptr;
	}
}

cell CValue::Get() const
{
	switch (m_valueType)
	{
		case INTEGER:
			return reinterpret_cast<cell>(m_pValue);
		case FLOAT:
		{
			cell value = reinterpret_cast<cell>(m_pValue);
			return amx_ctof(value);
		}
	}

	return 0;
}

cell* CValue::GetArray() const
{
	if (m_valueType != ARRAY)
		return nullptr;

	return m_pValue;
}
