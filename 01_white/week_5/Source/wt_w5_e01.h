#pragma once
#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace ::std;

namespace white::w5 {
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int y, int m, int d):day(d),month(m),year(y){}
    int GetYear() const{return year;}
    int GetMonth() const{return month;}
    int GetDay() const{return day;}
    friend bool operator<(const Date &l, const Date &r);
    friend bool operator==(const Date &l, const Date &r);
};

bool operator<(const Date& l, const Date& r)
{
    return (l.year < r.year) ||
            (l.year == r.year && l.month < r.month) ||
            (l.year == r.year && l.month == r.month && l.day < r.day);
}

bool operator==(const Date& l, const Date& r)
{
    return (l.year == r.year && l.month == r.month && l.day == r.day);
}

class Database {
private:
    map<Date, set<string>> vEvents;
public:
    void AddEvent(const Date& date, const string& event)
    {
        vEvents[date] = event;
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        if(vEvents.find(date) != vEvents.end())
        {
            vEvents.erase(vEvents.find(date));
        }
    }
    int  DeleteDate(const Date& date)
    {

    }

    string Find(const Date& date) const
    {
        if(vEvents.find(date) != vEvents.end())
        {
            return vEvents[date];
        }
        return {};
    }

    void Print() const;
};

void Requests(istream & is)
{

}
int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
    }

    return 0;
}
}
