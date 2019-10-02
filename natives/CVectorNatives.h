#pragma once

class CVectorNatives
{
private:
	static CContainerManager<std::vector<CValue>> ms_vectorManager;

public:
	static cell AMX_NATIVE_CALL CreateVector(AMX* pAmx, cell* pParams);
	static cell AMX_NATIVE_CALL DeleteVector(AMX* pAmx, cell* pParams);
};