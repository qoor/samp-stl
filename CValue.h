#pragma once

enum eValueType
{
	NONE,
	INTEGER,
	FLOAT,
	ARRAY
};

class CValue
{
private:
	eValueType m_valueType;
	cell* m_pValue;
	cell m_valueSize;

public:
	CValue() : m_valueType(NONE), m_pValue(nullptr), m_valueSize(0) { }
	CValue(eValueType valueType, cell value, cell valueSize = 1);
	~CValue();

	eValueType GetType() const;
	cell Get() const;
	bool GetArray(cell** pOutArrayPointer, cell* pOutSize) const;
};
