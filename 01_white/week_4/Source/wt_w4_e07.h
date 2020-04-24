#pragma once

#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace ::std;
class Day{
public:
    int day;
    explicit Day(int d):day(d){
        if(day < 0 || day > 31){
            throw invalid_argument("Day: "+to_string(d));
        }
    }
};
class Month{
public:
    int month;
    explicit Month(int m):month(m){
        if(month < 0 || month > 12){
            throw invalid_argument("Day: "+to_string(m));
        }

    }
};
class Year{
public:
    int year;
    explicit Year(int y):year(y){
        if(year < 0){
            throw invalid_argument("Year: "+to_string(y));
        }
    }
};
class Student{
public:
    string fname;
    string lname;
    Day day;
    Month month;
    Year year;
    explicit Student(string const & _fname, string const & _lname, Day & d, Month & m, Year const & y):
        fname(_fname),
        lname(_lname),
        day(d),
        month(m),
        year(y)
    {}
};

namespace white::w4::e07 {
string StudentInfo(vector<string> & requests){
    return {};
}
}




