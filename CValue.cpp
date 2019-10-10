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

eValueType CValue::GetType() const
{
	return m_valueType;
}

cell CValue::Get() const
{
	assert(m_valueType != ARRAY);
	return reinterpret_cast<cell>(m_pValue);
}

bool CValue::GetArray(cell** pOutArrayPointer, cell* pOutSize) const
{
	assert(pOutArrayPointer != nullptr);
	assert(pOutSize != nullptr);

	if (m_valueType != ARRAY)
	{
		return false;
	}

	*pOutArrayPointer = m_pValue;
	*pOutSize = m_valueSize;
	return true;
}
