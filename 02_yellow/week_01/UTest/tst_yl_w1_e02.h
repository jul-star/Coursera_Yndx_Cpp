#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <yl_w1_e02.h>
#include <sstream>

using namespace ::std;
using namespace ::yellow::w1;
using namespace ::testing;

namespace yellow::w1::ts  {
class yl_w1_e02_t:public ::testing::Test{

};

TEST_F(yl_w1_e02_t, Sum_00)
{
    stringstream ss;
    ss.clear();
    ss << 2 << ' ' << 1 << ' ' << 2 << endl;
    ss << 1 << ' ' << 2 << ' ' << 3 << endl;
    ss << 3 << ' ' << 4 << ' ' << 5 << endl;
    int actual = ex_02(ss);
    int expected{126};
    EXPECT_EQ(expected, actual);
    ss.clear();
}

TEST_F(yl_w1_e02_t, Sum_01)
{
    stringstream ss;
    ss.clear();
    ss << 2 << ' ' << 14 << ' ' << 14 << endl;
    ss << 1 << ' ' << 2 << ' ' << 3 << endl;
    ss << 30 << ' ' << 40 << ' ' << 50 << endl;
    int actual = ex_02(ss);
    int expected{840'084};
    EXPECT_EQ(expected, actual);
    ss.clear();
}

TEST_F(yl_w1_e02_t, Sum_02)
{
    stringstream ss;
    ss.clear();
    ss << 2 << ' ' << 1 << ' ' << 4 << endl;
    ss << 1 << ' ' << 2 << ' ' << 3 << endl;
    ss << 30 << ' ' << 40 << ' ' << 50 << endl;
    int actual = ex_02(ss);
    int expected{240'006};
    EXPECT_EQ(expected, actual);
    ss.clear();
}
}



