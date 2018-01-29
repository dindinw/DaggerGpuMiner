if (NOT MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
endif()

set(SOURCES
    CpuInfo.cpp
    CpuInfo.h
    PathUtils.cpp
    PathUtils.h
    Random.cpp
    Random.h
    StringFormat.h
    Utils.cpp
    Utils.h
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(..)

add_library(Utils ${SOURCES})


