#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

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

    static int BuildInt(size_t bg, size_t sz, string const & s)
    {
        vector<int> v;
        for(size_t i = bg; i < sz; ++i)
        {
            string val{s[i]};
            int t = atoi(val.c_str());
            v.push_back(t);
        }
        int res{0};
        int m=1;
        for(vector<int>::reverse_iterator it=v.rbegin(); it != v.rend(); ++it)
        {
            res += m*(*it);
            m *= 10;
        }
        return res;
    }

    friend istream & operator>>(istream & is, Rational & r)
    {
        string s{};
        is >> s;
        if (s.empty()){
            r = Rational();
            return is;
        }
        size_t delimiter = s.find('/');
        if (delimiter == string::npos)
        {
            r = Rational();
            return is;
        }
        int n = BuildInt(0, delimiter, s);
        int d = BuildInt(delimiter+1, s.size(), s);
        Rational tmp(n,d);
        r = tmp;
        return is;
    }
    friend bool operator!=(Rational const &l, Rational const &r)
    {
        return (l.vNumerator!=r.vNumerator || l.vDenominator!=r.vDenominator);
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




