#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w4_e08.h>
#include <string>

using namespace ::std;
using namespace ::white::w4::e08;
using namespace ::testing;
namespace white::w4::ts {
class wt_w4_e08: public Test{
public:
    string path{"C:\\Projects\\C++\\Coursera_Yndx_Cpp\\01_white\\week_4\\Data\\"};
};

TEST_F(wt_w4_e08, part1_1)
{
    const Rational r(3, 10);
    EXPECT_TRUE(r.Numerator() == 3 && r.Denominator() == 10) << "Rational(3, 10) != 3/10    " << r.Numerator() << "/" << r.Denominator();
}

TEST_F(wt_w4_e08, part1_2)
{
    const Rational r(8, 12);
    EXPECT_TRUE(r.Numerator() == 2 && r.Denominator() == 3) << "Rational(8, 12) != 2/3  " << r.Numerator() << "/" << r.Denominator();

}
TEST_F(wt_w4_e08, part1_3)
{
    const Rational r(-4, 6);
    EXPECT_TRUE(r.Numerator() == -2 && r.Denominator() == 3)  << "Rational(-4, 6) != -2/3   " << r.Numerator() << "/" << r.Denominator();

}
TEST_F(wt_w4_e08, part1_4)
{
    const Rational r(4, -6);
    EXPECT_TRUE(r.Numerator() == -2 && r.Denominator() == 3) << "Rational(4, -6) != -2/3    "  << r.Numerator() << "/" << r.Denominator();
}
TEST_F(wt_w4_e08, part1_5)
{
    const Rational r(0, 15);
    EXPECT_TRUE(r.Numerator() == 0 && r.Denominator() == 1) << "Rational(0, 15) != 0/1  " << r.Numerator() << "/" << r.Denominator();

}
TEST_F(wt_w4_e08, part1_6)
{
    const Rational r;
    EXPECT_TRUE(r.Numerator() == 0 && r.Denominator() == 1)  << "Rational() != 0/1  " << r.Numerator() << "/" << r.Denominator();
}

TEST_F(wt_w4_e08, part2_1)
{
    Rational r1(4, 6);
    Rational r2(2, 3);
    EXPECT_TRUE(r1 == r2);
}
TEST_F(wt_w4_e08, part2_2)
{
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;
    EXPECT_TRUE(c == Rational(2, 1)) << "c = " << c;
}
TEST_F(wt_w4_e08, part2_3)
{
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;
    EXPECT_TRUE(c == Rational(31, 63)) << "c = " << c;
}
TEST_F(wt_w4_e08, part3_1)
{
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    EXPECT_TRUE(c == Rational(8, 9)) << "c = " << c;
}
TEST_F(wt_w4_e08, part3_2)
{
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    EXPECT_TRUE(c == Rational(2, 3)) << "c = " << c;
}

TEST_F(wt_w4_e08, part4_1)
{
    ostringstream output;
    output << Rational(-6, 8);
    EXPECT_TRUE(output.str() == "-3/4");
}

TEST_F(wt_w4_e08, part4_2)
{
    istringstream input("5/7");
    Rational r;
    input >> r;
    EXPECT_TRUE(r == Rational(5, 7)) << r;
}
TEST_F(wt_w4_e08, part4_3)
{
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    EXPECT_TRUE(r1 == Rational(5, 7) && r2 == Rational(5, 4)) << r1 << "    " << r2;

    input >> r1;
    input >> r2;
    EXPECT_TRUE(r1 != Rational(5, 7) && r2 != Rational(5, 4)) << r1 << "    " << r2;
}

TEST_F(wt_w4_e08, part5_1)
{
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    EXPECT_TRUE (rs.size() == 3)  << "Wrong amount of items in the set: " << rs.size() ;

    vector<Rational> v;
    for (auto x : rs) {
        v.push_back(x);
    }
    vector<Rational> expected{{1, 25}, {1, 2}, {3, 4}};
    EXPECT_TRUE (v == expected)  << "Rationals comparison works incorrectly" ;
}

TEST_F(wt_w4_e08, part5_2)
{
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];
    ++count[{2, 3}];

    EXPECT_TRUE (count.size() == 2) << "Wrong amount of items in the map: " << count.size() ;
}

}

