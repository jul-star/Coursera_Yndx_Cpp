#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <string>

using namespace ::std;

namespace white::w4::e04 {
static inline string GetFilePath4w4e04Input()
{
    return "C:\\Projects\\C++\\Coursera_Yndx_Cpp\\01_white\\week_4\\Data\\wt_w4_e04_input.txt";
}

static inline string GetFilePath4w4e04Output()
{
    return "C:\\Projects\\C++\\Coursera_Yndx_Cpp\\01_white\\week_4\\Data\\wt_w4_e04_output.txt";
}
void OpenFile(ifstream & f)
{
    try {
        f.open((GetFilePath4w4e04Input()));
    } catch (exception &ex) {
       throw string(ex.what());
    }
}

string task1()
{
    ifstream f;
    OpenFile(f);
    stringstream ss{};
    string str{};
    while(getline(f,str))
    {
        ss << str << '\n';
    }
    f.close();
    return ss.str();
}
void task2()
{
    ifstream f;
    OpenFile(f);
    ofstream o{};
    o.open(GetFilePath4w4e04Output(), ios::out);
    o << f.rdbuf();
    f.close();
    o.close();
}

}
