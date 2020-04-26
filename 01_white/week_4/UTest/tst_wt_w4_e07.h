#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e07.h>
#include <string>

using namespace ::std;
using namespace ::white::w4::e07;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e07: public Test{
public:
    string path{"C:\\Projects\\C++\\Coursera_Yndx_Cpp\\01_white\\week_4\\Data\\"};
};

TEST_F(wt_w4_e07, task1)
{
    string FileName{path};
    FileName.append("wt_w4_e07.txt");
    ifstream fl;
    fl.open(FileName);
    if(!fl.good())
    {
        FAIL() << "Can't find a test file.";
    }
    vector<string> actual = RunRequestOnStudentInfo(fl);
    vector<string> expected{
        "Ivan Ivanov",
        "3.3.1903",
        "bad request"
    };
    fl.close();
    EXPECT_EQ(expected,actual);
}

}
