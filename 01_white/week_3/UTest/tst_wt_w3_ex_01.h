#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_ex_01.h>

using namespace white::w3;
using namespace testing;

namespace white::w3::ts  {
TEST(wt_w3_ex_01, Sort_01)
{
    std::vector<int> actual{-4,3};
    ex_01(actual);
    std::vector<int> expected{3,-4};
    EXPECT_EQ(expected, actual);
}

TEST(wt_w3_ex_01, Sort_02)
{
    std::vector<int> actual{1, -3, 2};
    ex_01(actual);
    std::vector<int> expected{1, 2, -3};
    EXPECT_EQ(expected, actual);
}
}



