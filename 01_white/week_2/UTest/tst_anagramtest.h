#ifndef TST_ANAGRAMTEST_H
#define TST_ANAGRAMTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Anagram.h>

using namespace white;
using namespace testing;

TEST(AnagramTest, AnagramTest)
{
    EXPECT_EQ(10, 10);
    ASSERT_THAT(0, Eq(0));
}

TEST(AnagramTest, CheckIsAnagramm)
{
    bool actual = Anagram::IsAnagramm("solo", "loso");
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(AnagramTest, CheckIsAnagramm_False)
{
    bool actual = Anagram::IsAnagramm("solo", "los");
    bool expected = true;
    EXPECT_NE(expected, actual);
}

TEST(AnagramTest, CheckCountWords_solo)
{
    int actual = Anagram::CountWords("solo");
    int expected = 12;
    EXPECT_EQ(expected, actual);
}

TEST(AnagramTest, CheckCountWords_ANAGRAM)
{
    int actual = Anagram::CountWords("ANAGRAM");
    int expected = 840;
    EXPECT_EQ(expected, actual);
}
TEST(AnagramTest, CheckCountWords_PERMUTATION)
{
    int actual = Anagram::CountWords("PERMUTATION");
    int expected = 19958400;
    EXPECT_EQ(expected, actual);
}


#endif // TST_ANAGRAMTEST_H
