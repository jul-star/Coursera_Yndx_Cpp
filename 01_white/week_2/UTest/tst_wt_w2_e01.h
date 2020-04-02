#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;
namespace wt::w2::ts {
class wt_w2_e01:public ::testing::Test{

    // Test interface
private:
    void TestBody() override;
};
void wt_w2_e01::TestBody(){}

TEST(wt_w2_e01, wt_wk2_e01)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
}




