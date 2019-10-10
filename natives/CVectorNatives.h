#pragma once

class CVectorNatives
{
private:
	static CContainerManager<std::vector<CValue>> ms_vectorManager;

public:
	static cell AMX_NATIVE_CALL CreateVector(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL DeleteVector(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL GetSize(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL GetMaxSize(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL SetResize(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL GetCapacity(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL IsEmpty(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL SetReserve(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL ShrinkToFit(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL PushIntValue(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL PushFloatValue(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL PushArrayValue(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL PopValue(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL GetValueByInt(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL GetValueByFloat(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL GetValueByArray(AMX* pAmx, cell* pParams);
};
