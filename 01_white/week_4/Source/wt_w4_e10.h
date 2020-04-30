#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace ::std;

namespace white::w4::e10
{
class Rational10
{
private:
    int vNumerator{0};
    int vDenominator{1};
public:
    Rational10() {
        Initialize(0,1);
    }

    Rational10(int numerator, int denominator)
    {
        Initialize(numerator, denominator);
    }

    int Numerator() const {
        return vNumerator;
    }

    int Denominator() const {
        return vDenominator;
    }

    friend Rational10 operator+(Rational10 const & l, Rational10 const & r)
    {
        return Rational10(l.Numerator()*r.Denominator() + r.Numerator()*l.Denominator(), l.Denominator()*r.Denominator());
    }
    friend Rational10 operator-(Rational10 const & l, Rational10 const & r)
    {
        return Rational10(l.Numerator()*r.Denominator() - r.Numerator()*l.Denominator(), l.Denominator()*r.Denominator());
    }
    friend Rational10 operator*(Rational10 const & l, Rational10 const & r)
    {
        return Rational10(l.Numerator() * r.Numerator(), l.Denominator()*r.Denominator());
    }
    friend Rational10 operator/(Rational10 const & l, Rational10 const & r)
    {
        if (l.Denominator()* r.Numerator() == 0)
        {
            throw domain_error("Division by zero");
        }
        return Rational10(l.Numerator()*r.Denominator() , l.Denominator()* r.Numerator());
    }

    friend ostream & operator<<(ostream & os, Rational10 const & r)
    {
        os << r.Numerator() << "/" << r.Denominator();
        return os;
    }
    friend istream & operator>>(istream & is, Rational10 & r)
    {
        string s{};
        is >> s;
        if (s.empty()){
            r = Rational10();
            return is;
        }
        size_t delimiter = s.find('/');
        if (delimiter == string::npos)
        {
            r = Rational10();
            return is;
        }
        int n = BuildInt(0, delimiter, s);
        int d = BuildInt(delimiter+1, s.size(), s);
        Rational10 tmp(n,d);
        r = tmp;
        return is;
    }

    friend bool operator!=(Rational10 const &l, Rational10 const &r)
    {
        return (l.vNumerator!=r.vNumerator || l.vDenominator!=r.vDenominator);
    }
    friend bool operator<(Rational10 const &l, Rational10 const &r)
    {
        return (l.vNumerator*r.vDenominator < r.vNumerator*l.vDenominator);
    }
    friend bool operator==(Rational10 const & l, Rational10 const & r)
    {
        return (l.Numerator() == r.Numerator() && l.Denominator() == r.Denominator());
    }


private:
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

    void Initialize(int numerator, int denominator){
        if (denominator == 0)
        {
            throw invalid_argument("Invalid argument");
        }
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




