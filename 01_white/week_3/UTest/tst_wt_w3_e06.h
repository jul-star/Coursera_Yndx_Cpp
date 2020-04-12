#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e06.h>

using namespace ::testing;
using namespace white::w3;

namespace ts {
class wt_w3_e06: public Test
{

};
TEST_F(wt_w3_e06, Ctor)
{
    ReversibleString s("live");
    string actual = s.ToString();
    string expected{"live"};
    EXPECT_EQ(expected, actual);
}

TEST_F(wt_w3_e06, Reverse)
{
    ReversibleString s("live");
    string actual = s.Reverse();
    string expected{"evil"};
    EXPECT_EQ(expected, actual);
}
TEST_F(wt_w3_e06, ToString)
{
    ReversibleString s("live");
    string actual = s.ToString();
    string expected{"live"};
    EXPECT_EQ(expected, actual);
}
}
