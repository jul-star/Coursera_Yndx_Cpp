#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e05.h>
#include <string>

using namespace ::std;
using namespace ::white::w4::e05;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e05: public Test{
public:
    string path{"C:\\Projects\\C++\\Coursera_Yndx_Cpp\\01_white\\week_4\\Data\\"};
};
TEST_F(wt_w4_e05, task1)
{
    string actual{};
    try {
        actual = task1(path.append("wt_w4_e05_01.txt"));
    } catch (string &s) {
        FAIL() << s;
    }
    string expected{"5.000\n0.346\n10.400\n"};
    EXPECT_EQ(expected, actual) << actual;
}
TEST_F(wt_w4_e05, task2)
{
    string actual{};
    try {
        actual = task1(path.append("wt_w4_e05_02.txt"));
    } catch (string &s) {
        FAIL() << s;
    }
    string expected{"3.334\n3.333\n3.300\n"};
    EXPECT_EQ(expected, actual) << actual;
}
}
