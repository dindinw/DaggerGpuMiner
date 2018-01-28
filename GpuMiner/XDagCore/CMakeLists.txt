if (NOT MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
endif()

set(SOURCES
    dar/crc.h
    dar/crc_c.cpp
    dfstools/dfslib_crypt.cpp
    dfstools/dfslib_crypt.h
    dfstools/dfslib_string.cpp
    dfstools/dfslib_string.h
    dfstools/dfslib_types.h
    XAddress.cpp
    XAddress.h
    XBlock.cpp
    XBlock.h
    XCpuMiner.cpp
    XCpuMiner.h
    XHash.cpp
    XHash.h
    XHash.hpp
    XNetwork.cpp
    XNetwork.h
    XPool.cpp
    XPool.h
    XStorage.cpp
    XStorage.h
    XTaskProcessor.cpp
    XTaskProcessor.h
    XTaskWrapper.cpp
    XTaskWrapper.h
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(..)

add_library(XDagCore ${SOURCES})
target_link_libraries(XDagCore PUBLIC Hash)




