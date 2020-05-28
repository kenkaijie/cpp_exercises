#include <gtest/gtest.h>
#include <string>

#include "chapter2.hpp"
#include "boost/type_traits.hpp"

using namespace TemplateMetaprogramming;

TEST(template_metaprogramming_chapter2, excercise_2_0_check_same)
{
    static_assert(boost::is_same<add_const_ref<int>::type, int const &>::value, "");
    static_assert(boost::is_same<add_const_ref<int const &>::type, int const &>::value, "");
    static_assert(boost::is_same<add_const_ref<int &>::type, int const &>::value, "");
    static_assert(boost::is_same<add_const_ref<int const>::type, int const &>::value, "");

    ASSERT_TRUE(true);
}

TEST(template_metaprogramming_chapter2, excercise_2_1_check_same)
{
    static_assert(boost::is_same<replace_type<void*, void, int>::type, int*>::value, "");
    static_assert(boost::is_same<replace_type<int const*[10] , int const, long>::type, long * [10]>::value, "");
    static_assert(boost::is_same<replace_type<char& (*)(char&) , char&, long&>::type, long& (*)(long&)>::value, "");
    static_assert(boost::is_same<replace_type<char& (*)(int&) , char&, long&>::type, long& (*)(int&)>::value, "");
    ASSERT_TRUE(true);
}
