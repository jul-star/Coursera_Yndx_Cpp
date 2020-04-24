#pragma once

#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace ::std;

namespace white::w4::e06 {
string ConvertFile2Table(string & path){
    ifstream  fl{};
    try{
        fl.open(path);
    }catch(exception &e)
    {
        return {};
    }
    int rows{0};
    fl >> rows;
    fl.ignore(1);
    int cols{0};
    fl >> cols;
    stringstream ss(stringstream::in | stringstream::out);
    int i{0};
    for(int r=0;r<rows; ++r)
    {
        for(int c=0; c<cols; ++c){
            fl >> i;
            fl.ignore(1);
            ss << setw(10) << i;
        }
        ss << endl;
    }
    fl.close();
    return ss.str();
}
}




