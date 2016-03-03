# test_PosIn CMake config file
#
# This file sets the following variables:
# test_PosIn_FOUND - Always TRUE.
# test_PosIn_INCLUDE_DIRS - Directories containing the test_PosIn include files.
# test_PosIn_IDL_DIRS - Directories containing the test_PosIn IDL files.
# test_PosIn_LIBRARIES - Libraries needed to use test_PosIn.
# test_PosIn_DEFINITIONS - Compiler flags for test_PosIn.
# test_PosIn_VERSION - The version of test_PosIn found.
# test_PosIn_VERSION_MAJOR - The major version of test_PosIn found.
# test_PosIn_VERSION_MINOR - The minor version of test_PosIn found.
# test_PosIn_VERSION_REVISION - The revision version of test_PosIn found.
# test_PosIn_VERSION_CANDIDATE - The candidate version of test_PosIn found.

message(STATUS "Found test_PosIn-1.1.0")
set(test_PosIn_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(test_PosIn_INCLUDE_DIRS
#    "/usr/local/include/test_posin-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(test_PosIn_IDL_DIRS
#    "/usr/local/include/test_posin-1/idl")
set(test_PosIn_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(test_PosIn_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(test_PosIn_LIBRARIES
        "/usr/local/components/lib/libtest_posin.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(test_PosIn_LIBRARIES
        "/usr/local/components/lib/libtest_posin.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(test_PosIn_DEFINITIONS ${<dependency>_DEFINITIONS})

set(test_PosIn_VERSION 1.1.0)
set(test_PosIn_VERSION_MAJOR 1)
set(test_PosIn_VERSION_MINOR 1)
set(test_PosIn_VERSION_REVISION 0)
set(test_PosIn_VERSION_CANDIDATE )

