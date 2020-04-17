#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e01.h>

using namespace white::w4;
using namespace testing;

namespace white::w4::ts  {
class wt_w4_e01:public ::testing::Test{

};

TEST_F(wt_w4_e01, t1)
{
    LectureTitle title(
                Specialization("C++"),
                Course("White belt"),
                Week("4th")
                );
}

TEST_F(wt_w4_e01, doesnt_compiles_1)
{
    //    LectureTitle title("C++", "White belt", "4th");
}

TEST_F(wt_w4_e01, doesnt_compiles_2)
{
    //LectureTitle title = {"C++", "White belt", "4th"};
}
TEST_F(wt_w4_e01, doesnt_compiles_3)
{
    //LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
}
TEST_F(wt_w4_e01, doesnt_compiles_4)
{
    //    LectureTitle title(
    //        Course("White belt"),
    //        Specialization("C++"),
    //        Week("4th")
    //    );
}
TEST_F(wt_w4_e01, doesnt_compiles_5)
{
    //    LectureTitle title(
    //        Specialization("C++"),
    //        Week("4th"),
    //        Course("White belt")
    //    );
}
}

