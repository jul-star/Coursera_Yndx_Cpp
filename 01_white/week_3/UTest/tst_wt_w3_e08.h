#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e08.h>
#include <exception>

using namespace white::w3;
using namespace ::testing;

namespace ts {
class wt_w3_e08: public Test
{

};

TEST_F(wt_w3_e08, Ctor)
{
    try {
        Incognizable a;
    } catch (...) {
        FAIL();
    }
}
TEST_F(wt_w3_e08, Ctor1)
{
    try {
        Incognizable b = {};
    } catch (...) {
        FAIL();
    }
}
TEST_F(wt_w3_e08, Ctor2)
{
    try {
        Incognizable c = {0};
    } catch (...) {
        FAIL();
    }
}
TEST_F(wt_w3_e08, Ctor3)
{
    try {
        Incognizable d = {0, 1};
    } catch (...) {
        FAIL();
    }
}
}
