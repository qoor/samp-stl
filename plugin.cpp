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
	{ "vec_new", CVectorNatives::CreateVector },
	{ "vec_delete", CVectorNatives::DeleteVector },
	{ "vec_size", CVectorNatives::GetSize },
	{ "vec_max_size", CVectorNatives::GetMaxSize },
	{ "vec_resize", CVectorNatives::SetResize },
	{ "vec_capacity", CVectorNatives::GetCapacity },
	{ "vec_empty", CVectorNatives::IsEmpty },
	{ "vec_reserve", CVectorNatives::SetReserve },
	{ "vec_shrink_to_fit", CVectorNatives::ShrinkToFit },
	{ "vec_push_back_int", CVectorNatives::PushIntValue },
	{ "vec_push_back_float", CVectorNatives::PushFloatValue },
	{ "vec_push_back_array", CVectorNatives::PushArrayValue },
	{ "vec_pop_back", CVectorNatives::PopValue },
	{ "vec_at_int", CVectorNatives::GetValueByInt },
	{ "vec_at_float", CVectorNatives::GetValueByFloat },
	{ "vec_at_array", CVectorNatives::GetValueByArray },
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
