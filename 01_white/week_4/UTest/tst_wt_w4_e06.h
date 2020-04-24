#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e06.h>
#include <string>

using namespace ::std;
using namespace ::white::w4::e06;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e06: public Test{
public:
    string path{"C:\\Projects\\C++\\Coursera_Yndx_Cpp\\01_white\\week_4\\Data\\"};
};

TEST_F(wt_w4_e06, task1)
{
    string actual{};
    try {
        actual = ConvertFile2Table(path.append("wt_w4_e06.txt"));
    } catch (string &s) {
        FAIL() << s;
    }
    string expected{"         1         2         3\n         4         5         6\n"};
    EXPECT_EQ(expected, actual) << actual;
}

}
