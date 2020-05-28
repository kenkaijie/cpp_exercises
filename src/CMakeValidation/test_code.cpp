#include <gtest/gtest.h>
#include <string>

TEST(cmake_test_validation, test_true)
{
    bool actual = true;
    ASSERT_TRUE(actual == true);
}
