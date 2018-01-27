if (NOT MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
endif()

set(SOURCES
    sha256.cpp 
	sha256.h
    sha256_mod.cpp 
	sha256_mod.h
)

add_library(Hash ${SOURCES})

