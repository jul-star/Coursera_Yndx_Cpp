#pragma once
#include <algorithm>
#include <iostream>

using namespace ::std;

namespace white::w4::e08
{
class Rational
{
private:
    int vNumerator{0};
    int vDenominator{1};
public:
    Rational() {
        Initialize(0,1);
    }

    Rational(int numerator, int denominator)
    {
        Initialize(numerator, denominator);
    }

    int Numerator() const {
        return vNumerator;
    }

    int Denominator() const {
        return vDenominator;
    }
    friend Rational operator+(Rational const & l, Rational const & r)
    {
        return Rational(l.Numerator()*r.Denominator() + r.Numerator()*l.Denominator(), l.Denominator()*r.Denominator());
    }
    friend Rational operator-(Rational const & l, Rational const & r)
    {
        return Rational(l.Numerator()*r.Denominator() - r.Numerator()*l.Denominator(), l.Denominator()*r.Denominator());
    }
    friend bool operator==(Rational const & l, Rational const & r)
    {
        return (l.Numerator() == r.Numerator() && l.Denominator() == r.Denominator());
    }

    friend Rational operator*(Rational const & l, Rational const & r)
    {
        return Rational(l.Numerator() * r.Numerator(), l.Denominator()*r.Denominator());
    }
    friend Rational operator/(Rational const & l, Rational const & r)
    {
        return Rational(l.Numerator()*r.Denominator() , l.Denominator()* r.Numerator());
    }

    friend ostream & operator<<(ostream & os, Rational const & r)
    {
        os << r.Numerator() << "/" << r.Denominator();
        return os;
    }

    friend istream & operator>>(istream & is, Rational & r)
    {
        int n{0};
        int d{1};
        is >> n;
        is >> d;
        Rational tmp(n,d);
        r = tmp;
        return is;
    }

private:
    void Initialize(int numerator, int denominator){
        int d = GCD(numerator, denominator);
        if (numerator % d == 0 && denominator % d == 0)
        {
            vNumerator = numerator/d;
            vDenominator = denominator/d;
        }else{
            vNumerator = numerator;
            vDenominator = denominator;
        }
    }

    int GCD(int a, int b) {
        while (b) {
            a %= b;
            swap (a, b);
        }
        return a;
    }
};

}




