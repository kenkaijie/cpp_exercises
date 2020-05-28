add_library(chapter2 STATIC chapter2.cpp)
target_link_libraries(chapter2 PUBLIC Boost::type_traits)

package_add_g_test_with_libraries(chapter2_tests test_chapter2.cpp chapter2)