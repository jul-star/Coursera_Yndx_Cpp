#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_Input.h>
#include <sstream>

using namespace white::w3;
using namespace testing;

namespace white::w3::ts {
TEST(Input, ReadVector_test)
{
    std::stringstream ss;
    {
    ss << "3 1 2 3";
    std::vector<int> actual = Input::ReadVector(ss);
    std::vector<int> expected{1,2,3};
    EXPECT_EQ(expected, actual);
    }
    {
        ss << "1 1";
        std::vector<int> actual = Input::ReadVector(ss);
        std::vector<int> expected{1};
        EXPECT_EQ(expected, actual);
    }
    {
    ss << "2 1 2";
    std::vector<int> actual = Input::ReadVector(ss);
    std::vector<int> expected{1,2};
    EXPECT_EQ(expected, actual);
    }
    {
    ss << "0";
    std::vector<int> actual = Input::ReadVector(ss);
    std::vector<int> expected{};
    EXPECT_EQ(expected, actual);
    }
    {
    ss << "-2";
    std::vector<int> actual = Input::ReadVector(ss);
    std::vector<int> expected{};
    EXPECT_EQ(expected, actual);
    }
    {
    ss << "0 1";
    std::vector<int> actual = Input::ReadVector(ss);
    std::vector<int> expected{};
    EXPECT_EQ(expected, actual);
    }
}
}

