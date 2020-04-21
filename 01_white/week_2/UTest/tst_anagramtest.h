#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Anagram.h>

using namespace ::white;
using namespace ::testing;
namespace white::w2::ts  {
class wt_w2_e01: public Test{

    // Test interface
private:
    void TestBody() override;
};
void wt_w2_e01::TestBody(){}

TEST_F(wt_w2_e01, wt_w2_e01)
{
    EXPECT_EQ(10, 10);
    ASSERT_THAT(0, Eq(0));
}

TEST_F(wt_w2_e01, CheckIsAnagramm)
{
    bool actual = Anagram::IsAnagramm("solo", "loso");
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST_F(wt_w2_e01, CheckIsAnagramm_False)
{
    bool actual = Anagram::IsAnagramm("solo", "los");
    bool expected = true;
    EXPECT_NE(expected, actual);
}

TEST_F(wt_w2_e01, CheckCountWords_solo)
{
    int actual = Anagram::CountWords("solo");
    int expected = 12;
    EXPECT_EQ(expected, actual);
}

TEST_F(wt_w2_e01, CheckCountWords_ANAGRAM)
{
    int actual = Anagram::CountWords("ANAGRAM");
    int expected = 840;
    EXPECT_EQ(expected, actual);
}
TEST_F(wt_w2_e01, CheckCountWords_PERMUTATION)
{
    int actual = Anagram::CountWords("PERMUTATION");
    int expected = 19958400;
    EXPECT_EQ(expected, actual);
}

}
