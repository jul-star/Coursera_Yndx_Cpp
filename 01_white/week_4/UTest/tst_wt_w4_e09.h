#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e09.h>
#include <string>
#include <exception>

using namespace ::std;
using namespace ::white::w4::e09;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e09: public Test{

};
TEST_F(wt_w4_e09, t1)
{
    try {
        EnsureEqual("Hello", "Vasya");
        FAIL() << "equal";
    } catch (runtime_error &re) {
        return;
    }
    FAIL() << "Doesn't catch exception";
}

TEST_F(wt_w4_e09, t2)
{
    try {
        EnsureEqual("Hello", "hello");
        FAIL() << "equal";
    } catch (runtime_error &re) {
        return;
    }
    FAIL() << "Doesn't catch exception";
}

}

