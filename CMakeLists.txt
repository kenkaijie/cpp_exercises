cmake_minimum_required(VERSION 3.1...3.15)

project(CPP_EXCERCISES VERSION 0.1.1
                     DESCRIPTION "Validates intel hex files" 
                     LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(cmake/package_add_g_test.cmake)


enable_testing()
include(GoogleTest) # to get the gtest built-in macros working
# this is needed on windows when running MSVC
set( gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")
set(BOOST_ENABLE_CMAKE ON)
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost" "extern/boost")

add_subdirectory(src)

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)