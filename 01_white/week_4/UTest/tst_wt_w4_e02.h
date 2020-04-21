#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e02.h>
#include <sstream>

using namespace ::std;
using namespace ::white::w4::e02;
using namespace ::testing;

namespace white::w4::e2::ts  {
class wt_w4_e02: public ::testing::Test{

};

TEST_F(wt_w4_e02, t1)
{
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    stringstream ss;
    double actual{0.0};
    double expected{0.0};
    double tmp = ComputeImageWeight(params, image);
    ss << tmp;
    ss >> actual;
    expected = 36.0;
    EXPECT_DOUBLE_EQ(expected, actual) << " Expected: "<<expected << ", Actual: " << actual;

    actual = ComputeQualityByWeight(params, image, 46);
    expected = 20.0;
    EXPECT_DOUBLE_EQ(expected, actual) << " Expected: "<<expected << ", Actual: " << actual;
}

}

