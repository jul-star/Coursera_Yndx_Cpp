#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Sort_01.h>

using namespace white::w3;
using namespace testing;

namespace white::w3::ts  {
TEST(Tests, S01_test)
{
    EXPECT_EQ(1, Sort_01::S01());
    ASSERT_THAT(0, Eq(0));
}
}



