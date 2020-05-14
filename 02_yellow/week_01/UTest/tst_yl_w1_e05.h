#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <yl_w1_e05.h>
#include <vector>
#include <string>
#include <sstream>

using namespace ::std;
using namespace ::yellow::w1::e05;
using namespace ::testing;

namespace yellow::w1::ts  {
class yl_w1_e05_t:public ::testing::Test{

};


TEST_F(yl_w1_e05_t, Vec_01)
{
    vector<int> v = {1, 2, 3};
    stringstream ss;
    ss << "vector:";
    for (int x : Sqr(v)) {
        ss << ' ' << x;
    }
    string expected {"vector: 1 4 9"};
    EXPECT_EQ(expected, ss.str()) << ss.str();
    //
}

TEST_F(yl_w1_e05_t, map_simple)
{
    map<int, int> map_simple = {
        {4, 2},
        {7, 4}
    };
    stringstream ss;
    ss << "map_simple:" << endl;
    map<int, int> actual = Sqr(map_simple);
    for (const auto& x : actual) {
        ss << x.first << ' ' << x.second << endl;
    }
    string expected {"map_simple:\n4 4\n7 16\n"};
    EXPECT_EQ(expected, ss.str()) << ss.str();
}

TEST_F(yl_w1_e05_t, pair_simple)
{
    pair<int, int> pair_simple = {4, 2};
    stringstream ss;
    ss << "pair_simple:" << endl;
    pair<int, int> actual = Sqr(pair_simple);
        ss << actual.first << ' ' << actual.second;
    string expected {"pair_simple:\n16 4"};
    EXPECT_EQ(expected, ss.str()) << ss.str();
}

TEST_F(yl_w1_e05_t, map_of_pairs)
{
    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    stringstream ss;
    ss << "map of pairs:" << endl;
    map<int, pair<int, int>> actual = Sqr(map_of_pairs);
    for (const auto& x : actual) {
        ss << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    string expected {"map of pairs:\n4 4 4\n7 16 9\n"};
    EXPECT_EQ(expected, ss.str()) << ss.str();
}

}



