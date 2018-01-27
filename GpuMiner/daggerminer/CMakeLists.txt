
file(GLOB SRC_FILES
	main.cpp
)


# Add executable to build.

add_executable(daggerminer
	${SRC_FILES}
)


include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(..)

target_link_libraries(daggerminer
		  ${Boost_FILESYSTEM_LIBRARY}
		  ${Boost_SYSTEM_LIBRARY}
		  ${OPENCL_LIBRARIES}
		  Hash
		  Utils
		  XDagCore
		  Core
		  HashCL 
)

