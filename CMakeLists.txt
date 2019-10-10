cmake_minimum_required (VERSION 3.0)

set (CMAKE_LINK_DEF_FILE_FLAG "/DEF:plugin.def")

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/natives)

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
	"CContainer.cpp"
	"CContainer.h"
	"CSingleton.h"

	"natives/CVectorNatives.cpp"
	"natives/CVectorNatives.h"
)

add_library (samp-stl STATIC ${PROJECT_SOURCES})
