#ifndef TST_UNIQUESTRINGTEST_H
#define TST_UNIQUESTRINGTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(UniqueStringTest, UniqueStringTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_UNIQUESTRINGTEST_H
