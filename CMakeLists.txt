cmake_minimum_required(VERSION 3.2.2)


set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Let user override the used C++ standard by using the command line with
#     cmake -DCMAKE_CXX_STANDARD=11 ..
# (CAVEAT: will fail on constexpr bool islamic::year::is_leap() const if < 14)
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

project(demo LANGUAGES CXX)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)

# By adding this command we can see the full command line of the compiler 
# during compilation (make) for inspection
set(CMAKE_VERBOSE_MAKEFILE ON)

################################################################################
# Import library "date" from git submodule subfolder libs/date
add_subdirectory(libs/date) 

################################################################################
# Add the executable configured in src/CMakeLists.txt
add_subdirectory(src)

################################################################################
# Packaging configuration

# Debian installer prefix propagated to CMakeCPackConfig
set(DEB_INSTALL_PREFIX 
    "/opt/${PROJECT_NAME}-${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
configure_file(CMakeCPackConfig.cmake.in CMakeCPackConfig.cmake @ONLY)

################################################################################
# Package configuration
include(${CMAKE_SOURCE_DIR}/CMakeCPack.cmake)

################################################################################
# Additional installation files (see also install directives in subdirectories)
install(FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION doc)

# Also install the header files from the library date
install(DIRECTORY libs/date/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/date)

