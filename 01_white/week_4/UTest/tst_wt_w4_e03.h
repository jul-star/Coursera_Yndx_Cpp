#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e03.h>
#include <sstream>

using namespace ::std;
using namespace ::white::w4::e03;
using namespace ::testing;

namespace white::w4::e3::ts  {
class wt_w4_e03: public ::testing::Test{

};

TEST_F(wt_w4_e03, t1)
{
    Image1 image = {10, 2, 6};
    Params1 params = {4, 2, 6};
    stringstream ss;
    double actual{0.0};
    double expected{0.0};
    double tmp = Wrapper::ComputeImageWeight(params, image);
    ss << tmp;
    ss >> actual;
    expected = 36.0;
    EXPECT_DOUBLE_EQ(expected, actual) << " Expected: "<<expected << ", Actual: " << actual;

    actual = Wrapper::ComputeQualityByWeight(params, image, 46);
    expected = 20.0;
    EXPECT_DOUBLE_EQ(expected, actual) << " Expected: "<<expected << ", Actual: " << actual;
}

TEST_F(wt_w4_e03, t2)
{
    Image1 image = {10, 2, 6};
    Params1 params = {4, 2, 6};

    double actual = Wrapper::ComputeImageWeight(params, image);
    double expected = 72.0;
    EXPECT_DOUBLE_EQ(expected, actual) << " Expected: "<<expected << ", Actual: " << actual;

    actual = Wrapper::ComputeQualityByWeight(params, image, 52);
    expected = 5.0;
    EXPECT_DOUBLE_EQ(expected, actual) << " Expected: "<<expected << ", Actual: " << actual;
}


}

