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
    EXPECT_TRUE(r == Rational(5, 7));
}
TEST_F(wt_w4_e08, part4_3)
{
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    EXPECT_TRUE(r1 == Rational(5, 7) && r2 == Rational(5, 4));

    input >> r1;
    input >> r2;
    EXPECT_TRUE(r1 == Rational(5, 7) && r2 == Rational(5, 4));
}
}
/*

######################################################

#####################################################

########################################
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
    // Вставьте сюда реализацию класса Rational из первой части
};

// Вставьте сюда реализацию operator == для класса Rational из второй части

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
###########################################
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

class Rational {
public:
    Rational(int new_numerator = 0, int new_denominator = 1) {
        this->numerator = new_numerator;
        this->denominator = new_denominator;

        if (this->denominator == 0)
            this->numerator = 0;

        if (this->numerator == 0)
            this->denominator = 1;

        if (denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }

        Reduce();
    }

    int Numerator() const {
        return this->numerator;
    }

    int Denominator() const {
        return this->denominator;
    }

    Rational invert() const {
        return Rational(this->denominator, this->numerator);
    }

private:
    int numerator;
    int denominator;

    int GCD(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int LCM(int a, int b) {
        return a * b / GCD(a, b);
    }

    void Reduce() {
        int gcd = GCD(abs(this->numerator), abs(this->denominator));

        this->numerator   /= gcd;
        this->denominator /= gcd;

        return;
    }
};

bool operator == (const Rational& lhs, const Rational& rhs) {
    return ((lhs.Numerator()   == rhs.Numerator()  ) &&
            (lhs.Denominator() == rhs.Denominator()));
}

bool operator != (const Rational& lhs, const Rational& rhs) {
    return (!(lhs == rhs));
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

bool operator > (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return lhs * rhs.invert();
}

ostream& operator << (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
    if (stream.tellg() != -1) {
        int numerator, denominator;
        stream >> numerator;
        stream.ignore(1);
        stream >> denominator;
        rational = Rational(numerator, denominator);
    }
    return stream;
}

*/
