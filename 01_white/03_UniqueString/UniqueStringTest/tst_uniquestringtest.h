#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../UniqueString/UniqueString.h>
#include <vector>
#include <string>
#include <sstream>
#include <istream>

using namespace std;
using namespace white;
using namespace testing;

TEST(UniqueStringTest, UniqueStringTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(UniqueStringTest, ReadInput)
{
    stringstream s;
    s << 2 << "Hello" << ' ' << "world";
    vector<string> actual = UniqueString::ReadInput(s);
    vector<string> expected{"Hello", "world"};
    ASSERT_FALSE(actual.empty());
    ASSERT_EQ(expected.size(), actual.size());
    EXPECT_EQ(expected, actual);
}

TEST(UniqueStringTest, CountUnique)
{
    vector<string> input{"Hello", "world", "Hello"};
    size_t actual = UniqueString::CountUnique(input);
    size_t expected{2};
    EXPECT_EQ(expected, actual);
}




