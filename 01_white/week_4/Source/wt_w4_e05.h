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
    ifstream  fl{};
    try{
        fl.open(path);
    }catch(exception &e)
    {
        return {};
    }
    double d{0};
    stringstream ss(stringstream::in | stringstream::out);
    while (true) {
        fl >> d;
        if(fl.eof()){
            break;
        }
        double f = round(d*1E+3)/1E+3;
        ss << fixed << showpoint << setprecision(3) << f << endl; // ios_base::floatpoint
    }
    fl.close();
    return ss.str();
}
}




