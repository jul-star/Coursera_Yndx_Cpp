#pragma once

#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace ::std;

namespace white::w4::e05 {
string task1(string & path){
    ifstream  f{};
    try{
        f.open(path);
    }catch(exception &e)
    {
        return {};
    }
    double d{0};
    stringstream ss{};
    ss.precision(3);
    while (!f.eof()) {
        f >> d;
        double f = round(d*1E+3)/1E+3;
        ss << f << '\n';
    }
    return ss.str();
}
}




