#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e10.h>
#include <wt_w4_e11.h>
#include <string>
#include <sstream>

using namespace ::std;
using namespace ::white::w4::e10;
using namespace ::white::w4::e11;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e11: public Test{

};
TEST_F(wt_w4_e11, Invalid_argument)
{
    stringstream ss;
    ss << "1/2 + 5/0";
    string actual = CalculateRational10(ss);
    string expected{"Invalid argument"};
    EXPECT_EQ(expected, actual) << "actual: " << actual;
}

TEST_F(wt_w4_e11, Division_by_zero)
{
    stringstream ss;
    ss << "4/5 / 0/8";
    string actual = CalculateRational10(ss);
    string expected{"Division by zero"};
    EXPECT_EQ(expected, actual) << "actual: " << actual;
}
TEST_F(wt_w4_e11, Correct)
{
    stringstream ss;
    ss << "1/2 + 1/3";
    string actual = CalculateRational10(ss);
    string expected{"5/6"};
    EXPECT_EQ(expected, actual) << "actual: " << actual;
}
}

