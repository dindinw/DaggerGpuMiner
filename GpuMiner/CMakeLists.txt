cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

################### Variables. ####################
# Change if you want modify path or other values. #
###################################################

set(PROJECT_NAME GpuMiner)
# Output Variables
set(OUTPUT_DEBUG Debug/bin)
set(OUTPUT_RELEASE Release/bin)
# Folders files
#set(CPP_DIR_1 Core)
#set(CPP_DIR_2 HashCL)
#set(CPP_DIR_3 Hash)
set(CPP_DIR_4 ./)
#set(CPP_DIR_5 Utils)
#set(CPP_DIR_6 XDagCore/dar)
#set(CPP_DIR_7 XDagCore/dfstools)
#set(CPP_DIR_8 XDagCore)
#set(CPP_DIR_9 XDagCore/win)
set(HEADER_DIR_1 Core)
set(HEADER_DIR_2 HashCL)
set(HEADER_DIR_3 HashCL/CL)
set(HEADER_DIR_4 Hash)
set(HEADER_DIR_5 Utils)
set(HEADER_DIR_6 XDagCore/dar)
set(HEADER_DIR_7 XDagCore/dfstools)
set(HEADER_DIR_8 XDagCore)
#set(HEADER_DIR_9 XDagCore/win/netinet)
#set(HEADER_DIR_10 XDagCore/win/sys)

############## CMake Project ################
#        The main options of project        #
#############################################

project(${PROJECT_NAME} CXX)

# Define Release by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default.")
endif(NOT CMAKE_BUILD_TYPE)

# Definition of Macros

#add_definitions(
#   -D_CRT_SECURE_NO_WARNINGS 
#   -DCL_USE_DEPRECATED_OPENCL_2_0_APIS 
#   -D_WINSOCK_DEPRECATED_NO_WARNINGS 
#   -D_WIN32_WINNT=0x0601 
#   -DUSE_OPENSSL_SHA 
#)

############## Artefacts Output #################
# Defines outputs , depending Debug or Release. #
#################################################

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
else()
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
endif()

################# Flags ################
# Defines Flags for Windows and Linux. #
########################################

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")

################################################################
# Compiler-specific C++11 activation.
################################################################
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
  execute_process(
    COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
  if (NOT (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8))
    message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.8 or greater.")
  endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-mismatched-tags -Qunused-arguments")
  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # In OSX, clang requires "-stdlib=libc++" to support C++11
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(DREAL_EXTRA_LINKER_FLAGS "-stdlib=libc++")
  endif ()
else ()
  message(FATAL_ERROR "Your C++ compiler does not support C++11.")
endif ()


set(CMAKE_CXX_FLAGS                "-Wall -Wextra -std=c++11 ${DREAL_EXTRA_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG          "-g -DDREAL_DEBUG -DDREAL_TRACE -fno-inline")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

set(OPENSSL_ROOT_DIR "/opt/openssl/")
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system )
find_package(OpenCL REQUIRED)

include_directories(
	${CMAKE_SOURCE_DIR}/..
    ${OPENSSL_INCLUDE_DIR}
	${BOOST_INCLUDE_DIR}
	${OPENCL_INCLUDE_DIR}
    ${INCLUDE_DIR}
)

add_subdirectory(Utils)
add_subdirectory(XDagCore)
add_subdirectory(Core)
add_subdirectory(HashCL)
add_subdirectory(Hash)
add_subdirectory(daggerminer)

################ Files ################
#   --   Add files to project.   --   #
#######################################


file(GLOB SRC_FILES
#   ${CPP_DIR_1}/*.cpp
#   ${CPP_DIR_2}/*.cpp
#   ${CPP_DIR_3}/*.cpp
    ${CPP_DIR_4}/*.cpp
#   ${CPP_DIR_5}/*.cpp
#   ${CPP_DIR_6}/*.cpp
#   ${CPP_DIR_7}/*.cpp
#   ${CPP_DIR_8}/*.cpp
#   ${CPP_DIR_9}/*.cpp
   ${HEADER_DIR_1}/*.h
    ${HEADER_DIR_2}/*.h
    ${HEADER_DIR_3}/*.h
    ${HEADER_DIR_4}/*.h
   ${HEADER_DIR_5}/*.h
   ${HEADER_DIR_6}/*.h
   ${HEADER_DIR_7}/*.h
   ${HEADER_DIR_8}/*.h
   ${HEADER_DIR_9}/*.h
   ${HEADER_DIR_10}/*.h
)

link_directories(${OpenCL_LIBRARY})

# Add executable to build.

#add_executable(${PROJECT_NAME} 
#	${SRC_FILES}
#)

#if(MSVC)
#   target_link_libraries(${PROJECT_NAME} OpenCL.lib shlwapi.lib )
#else()
#	target_link_libraries(${PROJECT_NAME} 
#		  ${Boost_FILESYSTEM_LIBRARY}
#		  ${Boost_SYSTEM_LIBRARY}
#		  ${OPENCL_LIBRARIES}
#		  XDagCore
#		  Core
#		  Hash
#		  HashCL 
#	)
#endif(MSVC)

