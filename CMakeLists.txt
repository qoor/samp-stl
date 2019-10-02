cmake_minimum_required (VERSION 3.0)

set (CMAKE_LINK_DEF_FILE_FLAG "/DEF:plugin.def")

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/natives)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/containers)

add_definitions(-DHAVE_STDINT_H -D)

set (PROJECT_SOURCES
	"StdInc.h"

	"SDK/amxplugin.cpp"

	"plugin.cpp"
	"plugin.h"
	"CIdentifier.cpp"
	"CIdentifier.h"
	"CValue.cpp"
	"CValue.h"

	"natives/CVectorNatives.cpp"
	"natives/CVectorNatives.h"

	"containers/CVector.cpp"
	"containers/CVector.h"
)

add_library (samp-stl STATIC ${PROJECT_SOURCES})
