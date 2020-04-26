#pragma once

#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iterator>

using namespace ::std;
namespace white::w4::e07
{
    enum class eRequest:int {Wrong, Name, Date};

class Day
{
public:
    int value;
    Day():value(0){}
    explicit Day(int d):value(d){
        if(value < 0 || value > 31){
            throw invalid_argument("Day: "+to_string(d));
        }
    }
};
class Month
{
public:
    int value;
    Month():value(0){}
    explicit Month(int m):value(m){
        if(value < 0 || value > 12){
            throw invalid_argument("Day: "+to_string(m));
        }

    }
};
class Year
{
public:
    int value;
    Year():value(0){}
    explicit Year(int y):value(y){
        if(value < 0){
            throw invalid_argument("Year: "+to_string(y));
        }
    }
};
class Student
{
public:
    string fname;
    string lname;
    Day day;
    Month month;
    Year year;
    Student(){}
    explicit Student(string const & _fname, string const & _lname, Day & d, Month & m, Year const & y):
        fname(_fname),
        lname(_lname),
        day(d),
        month(m),
        year(y)
    {}
    static string BuildName(istream & is)
    {
        string s{};
//        char c;
//        while (true) {
//            is >> c;
//            if (c == ' '){
//                break;
//            }
//            s += c;
//        }
        is >> s;
        return s;
    }
    friend istream& operator>> (istream & is, Student & sr){

        sr.fname = BuildName(is);
        sr.lname = BuildName(is);
        int val;
        is >> val;
        sr.day = Day(val);
        is.ignore(1);
        is >> val;
        sr.month = Month(val);
        is.ignore(1);
        is >> val;
        sr.year = Year(val);
        return is;
    }

    friend ostream& operator<<(ostream & os, Student &st)
    {
        os << st.fname << " "
           << st.lname << " "
           << st.year.value << ' '
           << st.month.value << ' '
           << st.day.value;
        return os;
    }
    static vector<Student> ReadInput(istream & is)
    {
        vector<Student> result;
        int NumberOfStudent{0};
        is >> NumberOfStudent;
        for(int i=0;i<NumberOfStudent; ++i)
        {
            Student s;
            is >> s;
            result.push_back(s);
        }
        return result;
    }
};

class Request
{
public:
    size_t StudentIndex{0};
    eRequest token{eRequest::Wrong};    

    static vector<Request> ReadInput(istream & is)
    {
        int NumberOfRequests{0};
        is >> NumberOfRequests;
        vector<Request> vr;

        for(int i = 0; i<NumberOfRequests; ++i)
        {
            vr.push_back(GetRequest(is));
        }
        return vr;
    }
    static Request GetRequest(istream & is)
    {
        Request r;
        string line;
//        getline(is, line);
//        stringstream ss{line};
        string token;
        is >> token;
        if(token == "name"){ r.token = eRequest::Name; }
        else if(token == "date") {r.token = eRequest::Date; }
        else{r.token = eRequest::Wrong; }

        is >> r.StudentIndex;
        return r;
    }
};

vector<string> RunRequestOnStudentInfo(istream & is){
    vector<string>  result;

    vector<Student> students = Student::ReadInput(is);

    vector<Request> requests = Request::ReadInput(is);
    for(Request const &r: requests )
    {
        switch (r.token) {
        case eRequest::Wrong : {result.push_back("bad request"); break;}
        case eRequest::Name :
        {
            string str{};
            Student & student = students.at(r.StudentIndex-1);
            str.append(student.fname)
                    .append(" ")
                    .append(student.lname);
            result.push_back(str);
            break;}
        case eRequest::Date :
        {
            string str{};
            Student & student = students.at(r.StudentIndex-1);
            str.append(to_string(student.day.value))
                    .append(".")
                    .append(to_string(student.month.value))
                    .append(".")
                    .append(to_string(student.year.value));
            result.push_back(str);
            break;
        }
        }
    }
    return result;
}

//vector<Student> (string const & file)
//{
//    ifstream fl;
//    fl.open(file);
//    if(!fl.good())
//        return {};
//    vector<Student> Students;
//    while(true){
//        Student student;
//        fl >> student;
//        if(fl.eof())
//            break;
//        Students.push_back(student);
//    }
//    return Students;
//}

}




