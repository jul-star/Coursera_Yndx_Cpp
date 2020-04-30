#pragma once
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <wt_w4_e10.h>

using namespace ::std;
using namespace ::white::w4::e10;

namespace white::w4::e11
{
string ApplyOperation(Rational10 const &l,char operation, Rational10 const &r);
string CalculateRational10(iostream & is)
{
    Rational10 l;
    Rational10 r;
    char operation;
    try {
        is >> l;
    } catch (invalid_argument &ia) {
        return ia.what();
    }

    is.ignore(1);
    is >> operation;
    is.ignore(1);
    try {
        is >> r;
    } catch (invalid_argument &ia) {
        return ia.what();
    }
    return ApplyOperation(l,operation,r);
}

string ApplyOperation(Rational10 const &l,char operation, Rational10 const &r)
{
    stringstream ss{};
    if (operation == '+')
    {
        ss << (l+r);
    }else if(operation == '-')
    {
        ss << (l+r);
    }else if(operation == '*')
    {
        ss << (l+r);
    }else if(operation == '/')
    {
        try {
            ss << (l+r);
        } catch (domain_error & de) {
            return de.what();
        }
    }
    return ss.str();
}


}




