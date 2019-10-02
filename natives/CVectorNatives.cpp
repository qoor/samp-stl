#include "StdInc.h"
#include "CVector.h"
#include "CVectorNatives.h"

CContainerManager<std::vector<CValue>> CVectorNatives::ms_vectorManager;

cell AMX_NATIVE_CALL CVectorNatives::CreateVector(AMX* pAmx, cell* pParams)
{
	return m_vectorManager.;
}

cell AMX_NATIVE_CALL CVectorNatives::DeleteVector(AMX* pAmx, cell* pParams)
{
	CVector* pList = GetVectorList(pAmx);

	if (pList != nullptr)
	{
		int id = static_cast<int>(pParams[1]);
		std::vector<CValue>* pVector = GetVector(pAmx)

		if (id < pList->m_vectors.size() && (*pList).m_vectors[id] != nullptr)
		{
			delete (*pList).m_vectors[id];
			(*pList).m_vectors[id] = nullptr;
			return 1;
		}
	}

	return 0;
}

bool CVectorNatives::AddVectorList(AMX* pAmx)
{
	if (GetVectorList(pAmx) == nullptr)
	{
		ms_vectors.insert(std::pair<AMX*, CVector>(pAmx, CVector()));
		return true;
	}

	return false;
}

bool CVectorNatives::RemoveVectorList(AMX* pAmx)
{
	CVector* pList = GetVectorList(pAmx);
	std::vector<CValue>* pVector = nullptr;

	if (pList != nullptr)
	{
		for (int i = 0; i < pList->m_vectors.size(); ++i)
		{
			pVector = (*pList).m_vectors[i];

			if (pVector != nullptr)
				delete pVector;
		}

		ms_vectors.erase(pAmx);
		return true;
	}

	return false;
}
