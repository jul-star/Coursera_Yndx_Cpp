#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <yl_w1_e06.h>
#include <vector>
#include <string>
#include <sstream>

using namespace ::std;
using namespace ::yellow::w1::e06;
using namespace ::testing;

namespace yellow::w1::ts  {
class yl_w1_e06_t:public ::testing::Test{

};

TEST_F(yl_w1_e06_t, Vec_01)
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    string actual = m[0];
    string expected{"newvalue"};
    EXPECT_EQ(expected, actual) << actual;
}

}



