#include "StdInc.h"
#include "CVectorNatives.h"

CContainerManager<std::vector<CValue>> CVectorNatives::ms_vectorManager;

cell AMX_NATIVE_CALL CVectorNatives::CreateVector(AMX* pAmx, cell* pParams)
{
	CContainer<std::vector<CValue>>* pList = nullptr;
	
	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		return pList->AddContainer(static_cast<size_t>(pParams[1]));
	}

	return -1;
}

cell AMX_NATIVE_CALL CVectorNatives::DeleteVector(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		return static_cast<cell>(pList->RemoveContainer(iId));
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::GetSize(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			return static_cast<cell>(pContainer->size());
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::GetMaxSize(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			return static_cast<cell>(pContainer->max_size());
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::SetResize(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			pContainer->resize(pParams[2]);
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::GetCapacity(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			return static_cast<cell>(pContainer->capacity());
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::IsEmpty(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			return static_cast<cell>(pContainer->empty());
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::SetReserve(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			pContainer->reserve(pParams[2]);
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::ShrinkToFit(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			pContainer->shrink_to_fit();
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::PushIntValue(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);
	
	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;
		
		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			pContainer->push_back(CValue(INTEGER, pParams[2]));
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::PushFloatValue(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			pContainer->push_back(CValue(FLOAT, pParams[2]));
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::PushArrayValue(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			cell* pValuePointer;

			amx_GetAddr(pAmx, pParams[2], &pValuePointer);
			assert(pValuePointer != nullptr);

			pContainer->push_back(CValue(ARRAY, reinterpret_cast<cell>(pValuePointer), pParams[3]));
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::PopValue(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			pContainer->pop_back();
			return 1;
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::GetValueByInt(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			CValue* pValue;

			pValue = &(pContainer->at(pParams[2]));
			assert(pValue != nullptr);

			if (pValue->GetType() == INTEGER)
			{
				cell* pDestination;

				amx_GetAddr(pAmx, pParams[3], &pDestination);
				assert(pDestination != nullptr);
				*pDestination = pValue->Get();
				return 1;
			}
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::GetValueByFloat(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			CValue* pValue;

			pValue = &(pContainer->at(pParams[2]));
			assert(pValue != nullptr);
			if (pValue->GetType() == FLOAT)
			{
				cell* pDestination;

				amx_GetAddr(pAmx, pParams[3], &pDestination);
				assert(pDestination != nullptr);
				*pDestination = pValue->Get();
				return 1;
			}
		}
	}

	return 0;
}

cell AMX_NATIVE_CALL CVectorNatives::GetValueByArray(AMX* pAmx, cell* pParams)
{
	int iId = static_cast<int>(pParams[1]);
	CContainer<std::vector<CValue>>* pList = nullptr;
	assert(pList != nullptr);

	if (ms_vectorManager.GetAmxContainer(&pList, pAmx))
	{
		assert(pList != nullptr);
		std::vector<CValue>* pContainer = nullptr;

		if (pList->GetContainer(&pContainer, iId))
		{
			assert(pContainer != nullptr);
			CValue* pValue;

			pValue = &(pContainer->at(pParams[2]));
			assert(pValue != nullptr);

			cell* pValuePointer;
			cell valueSize;

			if (pValue->GetArray(&pValuePointer, &valueSize))
			{
				cell* pDestination;
				cell pRequestSize = pParams[4];

				amx_GetAddr(pAmx, pParams[3], &pDestination);
				assert(pDestination != nullptr);
				std::copy(pValuePointer, pValuePointer + ((pRequestSize < valueSize) ? pRequestSize : valueSize), pDestination);
				return 1;
			}
		}
	}

	return 0;
}
