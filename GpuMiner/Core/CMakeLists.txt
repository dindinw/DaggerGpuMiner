if (NOT MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
endif()

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
find_package(Threads)

#include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(..)

#add_library(Core ${SOURCES})
add_library(Core ${SOURCES} ${HEADERS})

#target_link_libraries(Core PUBLIC HashCL)

target_link_libraries(Core PUBLIC Boost::boost Boost::system HashCL XDagCore Utils)
target_link_libraries(Core PRIVATE Threads::Threads)
