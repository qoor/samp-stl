#include "StdInc.h"

CValue::CValue(eValueType valueType, cell* pValue, cell valueSize)
{
	assert(pValue != nullptr);

	m_valueType = valueType;
	m_pValue = pValue;
	m_valueSize = valueSize;
}

CValue::~CValue()
{
	assert(m_pValue != nullptr);

	delete m_pValue;
	m_pValue = nullptr;
}

cell CValue::Get() const
{
	switch (m_valueType)
	{
		case INTEGER:
			return *m_pValue;
		case FLOAT:
			return amx_ctof(*m_pValue);
	}

	return 0;
}

cell* CValue::GetArray() const
{
	if (m_valueType != ARRAY)
		return nullptr;

	return m_pValue;
}
