#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_ex_02.h>

using namespace testing;
using namespace white::w3;

namespace white::w3::ts  {
TEST(wt_w3_ex_02, Sort_01)
{
    std::vector<std::string> actual{"q", "A"};
    ex_02(actual);
    std::vector<std::string> expected{ "A", "q"};
    EXPECT_EQ(expected, actual);
}


TEST(wt_w3_ex_02, Sort_02)
{
    std::vector<std::string> actual{"a", "C", "b"};
    ex_02(actual);
    std::vector<std::string> expected{"a", "b" , "C"};
    EXPECT_EQ(expected, actual);
}
}
