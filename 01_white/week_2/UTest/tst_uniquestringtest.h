#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "UniqueString.h"
#include <vector>
#include <string>
#include <sstream>
#include <istream>

using namespace ::std;
using namespace ::white;
using namespace ::testing;

class wt_w2_e03: public Test{

    // Test interface
private:
    void TestBody() override;
};
void wt_w2_e03::TestBody(){}

TEST_F(wt_w2_e03, ReadInput)
{
    stringstream s;
    s << 2 << "Hello" << ' ' << "world";
    vector<string> actual = UniqueString::ReadInput(s);
    vector<string> expected{"Hello", "world"};
    ASSERT_FALSE(actual.empty());
    ASSERT_EQ(expected.size(), actual.size());
    EXPECT_EQ(expected, actual);
}

TEST_F(wt_w2_e03, CountUnique)
{
    vector<string> input{"Hello", "world", "Hello"};
    size_t actual = UniqueString::CountUnique(input);
    size_t expected{2};
    EXPECT_EQ(expected, actual);
}




