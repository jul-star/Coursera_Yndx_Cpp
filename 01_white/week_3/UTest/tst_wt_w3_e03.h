#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e03.h>

using namespace testing;
using namespace white::w3;

namespace white::w3::ts  {
class wt_w3_e03: public Test{

};


TEST_F(wt_w3_e03, Sort_01)
{
    SortedStrings ss;
    ss.AddString("q");
    ss.AddString("A");
    std::vector<std::string> actual = ss.GetSortedStrings();
    std::vector<std::string> expected{ "A", "q"};
    EXPECT_EQ(expected, actual);
}


TEST_F(wt_w3_e03, Sort_02)
{
    SortedStrings ss;
    ss.AddString("a");
    ss.AddString("C");
    ss.AddString("b");
    std::vector<std::string> actual = ss.GetSortedStrings();
    std::vector<std::string> expected{ "C", "a", "b"};
    EXPECT_EQ(expected, actual);
}
TEST_F(wt_w3_e03, Sort_03)
{
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    {
    std::vector<std::string> actual = strings.GetSortedStrings();
    std::vector<std::string> expected{"first", "second", "third"};
    EXPECT_EQ(expected, actual);
    }
    strings.AddString("second");
    {
    std::vector<std::string> actual = strings.GetSortedStrings();
    std::vector<std::string> expected{"first", "second", "second", "third"};
    EXPECT_EQ(expected, actual);
    }
}
}
