#include "StdInc.h"
#include "plugin.h"
#include "CVectorNatives.h"

typedef void (*logprintf_t)(char* format, ...);

logprintf_t logprintf;

extern void* pAMXFunctions;

PLUGIN_EXPORT unsigned int Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = reinterpret_cast<logprintf_t>(ppData[PLUGIN_DATA_LOGPRINTF]);

	logprintf(" * SA-MP STL plugin loaded.");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload(void** ppData)
{
	logprintf(" * SA-MP STL plugin unloaded.");
}

AMX_NATIVE_INFO arrPluginNatives[] = {
	{ "vector_new", CVectorNatives::CreateVector },
	{ "vector_delete", CVectorNatives::DeleteVector },
	{ "vector_size", CVectorNatives::GetSize },
	{ "vector_max_size", CVectorNatives::GetMaxSize },
	{ "vector_push_back_int", CVectorNatives::PushIntValue },
	{ "vector_push_back_float", CVectorNatives::PushFloatValue },
	{ "vector_push_back_array", CVectorNatives::PushArrayValue },
	{ "vector_pop_back", CVectorNatives::PopValue },
	{ 0, 0 }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
	return amx_Register(amx, arrPluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
	return AMX_ERR_NONE;
}
