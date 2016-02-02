# test_OrienIn CMake config file
#
# This file sets the following variables:
# test_OrienIn_FOUND - Always TRUE.
# test_OrienIn_INCLUDE_DIRS - Directories containing the test_OrienIn include files.
# test_OrienIn_IDL_DIRS - Directories containing the test_OrienIn IDL files.
# test_OrienIn_LIBRARIES - Libraries needed to use test_OrienIn.
# test_OrienIn_DEFINITIONS - Compiler flags for test_OrienIn.
# test_OrienIn_VERSION - The version of test_OrienIn found.
# test_OrienIn_VERSION_MAJOR - The major version of test_OrienIn found.
# test_OrienIn_VERSION_MINOR - The minor version of test_OrienIn found.
# test_OrienIn_VERSION_REVISION - The revision version of test_OrienIn found.
# test_OrienIn_VERSION_CANDIDATE - The candidate version of test_OrienIn found.

message(STATUS "Found test_OrienIn-1.1.0")
set(test_OrienIn_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(test_OrienIn_INCLUDE_DIRS
#    "/usr/local/include/test_orienin-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(test_OrienIn_IDL_DIRS
#    "/usr/local/include/test_orienin-1/idl")
set(test_OrienIn_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(test_OrienIn_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(test_OrienIn_LIBRARIES
        "/usr/local/components/lib/libtest_orienin.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(test_OrienIn_LIBRARIES
        "/usr/local/components/lib/libtest_orienin.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(test_OrienIn_DEFINITIONS ${<dependency>_DEFINITIONS})

set(test_OrienIn_VERSION 1.1.0)
set(test_OrienIn_VERSION_MAJOR 1)
set(test_OrienIn_VERSION_MINOR 1)
set(test_OrienIn_VERSION_REVISION 0)
set(test_OrienIn_VERSION_CANDIDATE )

