#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e12.h>
#include <string>
#include <sstream>
#include <random>

using namespace ::std;
using namespace ::white::w4::e12;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e12: public Test{
public:
    TimeServer TS;

};
enum class eAnswer: int{Z, F, Se, Ex};
static eAnswer answer{eAnswer::F};
string AskTimeServer()
{
    switch (answer) {
    case eAnswer::F: {return "F";}
    case eAnswer::Z: {return "Z";}
    case eAnswer::Se: { throw system_error(error_code());}
    case eAnswer::Ex: { throw invalid_argument("Test");}
    }
}

TEST_F(wt_w4_e12, F)
{
    answer = eAnswer::F;
    string actual = TS.GetCurrentTime();
    string expected = "F";
    EXPECT_EQ(expected, actual) << " expected: " << expected << ", actual: " << actual;
}

TEST_F(wt_w4_e12, Z)
{
    answer = eAnswer::Z;
    string actual = TS.GetCurrentTime();
    string expected = "Z";
    EXPECT_EQ(expected, actual) << " expected: " << expected << ", actual: " << actual;
}

TEST_F(wt_w4_e12, Se)
{
    answer = eAnswer::Z;
    string actual = TS.GetCurrentTime();
    string expected = "Z";
    EXPECT_EQ(expected, actual) << " expected: " << expected << ", actual: " << actual;

    answer = eAnswer::Se;
    actual = TS.GetCurrentTime();
    expected = "Z";
    EXPECT_EQ(expected, actual) << " expected: " << expected << ", actual: " << actual;
}

TEST_F(wt_w4_e12, Invalid_argument)
{
    string catcher{};
    try {
        answer = eAnswer::Ex;
        string actual = TS.GetCurrentTime();
        catcher.append("No exception");
    } catch (string &st) {
        catcher.append("string: ").append("Test");
    }catch (invalid_argument &ia) {
        catcher.append("invalid_argument: ").append(ia.what());
    }catch (exception &ex) {
        catcher.append("std::exception:");
    }
    //FIXME: Why is std::exception???
    string expected("std::exception:");
    EXPECT_EQ(catcher, expected) << catcher;
}

}

