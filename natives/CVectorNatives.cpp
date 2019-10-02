#include "StdInc.h"
#include "CVectorNatives.h"

CContainerManager<std::vector<CValue>> CVectorNatives::ms_vectorManager;

cell AMX_NATIVE_CALL CVectorNatives::CreateVector(AMX* pAmx, cell* pParams)
{
	return ms_vectorManager.CreateContainer(pAmx);
}

cell AMX_NATIVE_CALL CVectorNatives::DeleteVector(AMX* pAmx, cell* pParams)
{
	int id = static_cast<int>(pParams[1]);

	return static_cast<cell>(ms_vectorManager.DeleteContainer(pAmx, id));
}

cell AMX_NATIVE_CALL CVectorNatives::PushIntValue(AMX* pAmx, cell* pParams)
{
	int id = static_cast<int>(pParams[1]);
	std::vector<CValue>* pContainer = ms_vectorManager.GetContainer(pAmx, id);

	if (pContainer)
		pContainer->push_back(CValue(INTEGER, pParams[2]));
}

cell AMX_NATIVE_CALL CVectorNatives::PushFloatValue(AMX* pAmx, cell* pParams)
{
	int id = static_cast<int>(pParams[1]);
	std::vector<CValue>* pContainer = ms_vectorManager.GetContainer(pAmx, id);

	if (pContainer)
		pContainer->push_back(CValue(INTEGER, pParams[2]));
}

cell AMX_NATIVE_CALL CVectorNatives::PushArrayValue(AMX* pAmx, cell* pParams)
{
	int id = static_cast<int>(pParams[1]);
	std::vector<CValue>* pContainer = ms_vectorManager.GetContainer(pAmx, id);

	if (pContainer)
	{
		cell* pPointer;
		
		amx_GetAddr(pAmx, pParams[2], &pPointer);
		pContainer->push_back(CValue(INTEGER, reinterpret_cast<cell>(pPointer), pParams[3]));
	}
}

cell AMX_NATIVE_CALL CVectorNatives::PopValue(AMX* pAmx, cell* pParams)
{
	int id = static_cast<int>(pParams[1]);
	std::vector<CValue>* pContainer = ms_vectorManager.GetContainer(pAmx, id);

	if (pContainer)
		pContainer->pop_back();
}
