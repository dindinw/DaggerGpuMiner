if (NOT MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
endif()

set(SOURCES
    Common.h
    CommonData.cpp
    CommonData.h
    Exceptions.h
    Farm.cpp
    Farm.h
    Guards.h
    Log.cpp
    Log.h
    Miner.cpp
    Miner.h
    MinerManager.cpp
    MinerManager.h
    Terminal.h
    Worker.cpp
	Worker.h
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(..)

add_library(Core ${SOURCES})

target_link_libraries(Core PUBLIC HashCL)
