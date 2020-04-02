#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e02.h>

using namespace testing;
using namespace white::w3;

namespace white::w3::ts  {
class wt_w3_e02:public ::testing::Test{
public:
    wt_w3_e02(){}

    // Test interface
private:
    void TestBody() override;
};
void wt_w3_e02::TestBody(){}

TEST_F(wt_w3_e02, Sort_01)
{
    std::vector<std::string> actual{"q", "A"};
    ex_02(actual);
    std::vector<std::string> expected{ "A", "q"};
    EXPECT_EQ(expected, actual);
}


TEST_F(wt_w3_e02, Sort_02)
{
    std::vector<std::string> actual{"a", "C", "b"};
    ex_02(actual);
    std::vector<std::string> expected{"a", "b" , "C"};
    EXPECT_EQ(expected, actual);
}
}
