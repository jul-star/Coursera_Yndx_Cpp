#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <yl_w1_e01.h>
#include <sstream>

using namespace ::std;
using namespace ::yellow::w1;
using namespace ::testing;

namespace yellow::w1::ts  {
class yl_w1_e01_t:public ::testing::Test{

};

TEST_F(yl_w1_e01_t, Mean_01)
{
    stringstream ss;
    ss << 5 << endl;
    ss << 5 << ' ' << 4 << ' ' << 1<< ' ' << -2 << ' ' << 7 << endl;
    vector<int> actual = ex_01(ss);
    vector<int> expected{0,1,4};
    EXPECT_EQ(expected, actual);
}

TEST_F(yl_w1_e01_t, Mean_02)
{
    stringstream ss;
    ss << 5 << endl;
    ss << 50'000'000 << ' ' << 40'000'000 << ' ' << 1'000'000 << ' ' << -20'000'000 << ' ' << 7'000'000 << endl;
    vector<int> actual = ex_01(ss);
    vector<int> expected{0,1};
    EXPECT_EQ(expected, actual);
}
}



