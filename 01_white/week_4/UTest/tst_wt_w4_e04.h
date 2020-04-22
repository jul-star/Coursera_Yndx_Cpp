#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e04.h>
#include <string>

using namespace ::std;
using namespace ::white::w4::e04;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e04: public Test{

};
TEST_F(wt_w4_e04, task1)
{
    string actual{};
    try {
        actual = task1();
    } catch (string &s) {
        FAIL() << s;
    }
    string expected{"Kepp calm\nand\nlearn C++\n"};
    EXPECT_EQ(expected, actual) << actual;
}
TEST_F(wt_w4_e04, task2)
{
    task2();
}
}
