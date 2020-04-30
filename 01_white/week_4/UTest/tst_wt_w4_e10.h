#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e10.h>
#include <string>

using namespace ::std;
using namespace ::white::w4::e10;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e10: public Test{

};
TEST_F(wt_w4_e10, invalid_argument)
{
    try {
        Rational10 r(1, 0);
        FAIL() << "Doesn't throw in case of zero denominator" << endl;
    } catch (invalid_argument&) {
        return;
    }
    FAIL() << "Wrong type of exception";
}
TEST_F(wt_w4_e10, domain_error)
{
    try {
        auto x = Rational10(1, 2) / Rational10(0, 1);
        FAIL() << "Doesn't throw in case of division by zero" << endl;

    } catch (domain_error&) {
        return;
    }
    FAIL() << "Wrong type of exception";
}


}

