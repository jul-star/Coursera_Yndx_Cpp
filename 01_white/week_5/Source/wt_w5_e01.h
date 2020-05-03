#pragma once
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <exception>
#include <vector>
#include <iomanip>

using namespace ::std;

namespace white::w5 {
class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(): year(0),month(0),day(0) {}
    explicit Date(int y, int m, int d): year(y),month(m), day(d){
        string err{};
        if (month < 1 || month > 12)
        {
            err.append("Month value is invalid: ").append(to_string(month));
        }
        if(err.empty() && (day < 1 || day > 31))
        {
            err.append("Day value is invalid: ").append(to_string(day));
        }
        if(!err.empty())
        {
            throw invalid_argument(err);
        }
    }
    int GetYear() const{return year;}
    int GetMonth() const{return month;}
    int GetDay() const{return day;}

    Date & operator=(const Date &r)
    {
        if(this != &r)
        {
            this->year = r.year;
            this->month = r.month;
            this->day = r.day;
        }
        return *this;
    }
    friend bool operator<(const Date &l, const Date &r);
    friend bool operator==(const Date &l, const Date &r);
    friend ostream & operator<<(ostream & os, const Date &d);
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
ostream & operator<<(ostream & os, const Date &d)
{

    os << setw(4) << setfill('0') << d.year << '-' << setw(2) << setfill('0') << d.month << '-' << setw(2) << setfill('0') << d.day;
    return os;
}
class Database {
private:
    map<Date, set<string>> vEvents;
    vector<string> log;
public:
    void AddEvent(const Date& date, const string& event)
    {
        vEvents[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        if(vEvents.find(date) != vEvents.end())
        {
            log.push_back("Deleted successfully");
            vEvents.at(date).erase(event);
//            cout << "Deleted successfully";
        }
    }
    int  DeleteDate(const Date& date)
    {
        if(vEvents.find(date) != vEvents.end())
        {
            int n = vEvents.at(date).size();
            string history = string("Deleted ").append(to_string(n)).append(" events");
//            cout << history;
            log.push_back(history);
            vEvents.erase(date);
            return n;
        }
        return 0;
    }

    string Find(const Date& date)
    {
        stringstream ss;
        if(vEvents.find(date) != vEvents.end())
        {
            for(auto const & e: vEvents.at(date))
            {
                ss << e ;
            }
            log.push_back(ss.str());
            return ss.str();
        }
        return {};
    }

    string Print()
    {
        stringstream ss;
        for(auto const & d:vEvents)
        {
            for(auto const & e: d.second)
            {
                ss << d.first << ' ' << e;
            }
        }
        log.push_back(ss.str());
//        cout << ss.str();
        return ss.str();
    }
    vector<string> Log()
    {
        return log;
    }
    void AddToLog(string const & s)
    {
        log.push_back(s);
    }
};
void RunRequest(Database & db,
                string const & command, int year, int month, int day, string const & event);

void ParseLine(string const & s,
               string & command,
               int & y , int & m, int & d,
               string & event)
{
    if (s.empty()) { return; }
    stringstream ss(s);
    ss >> command;  if(ss.eof()) { return ; }
    ss >> y;        if(ss.eof()) { return ; }
    ss.ignore(1);   if(ss.eof()) { return ; }
    ss >> m;        if(ss.eof()) { return ; }
    ss.ignore(1);   if(ss.eof()) { return ; }
    ss >> d;        if(ss.eof()) { return ; }
    ss.ignore(1);   if(ss.eof()) { return ; }
    ss >> event;    if(ss.eof()) { return ; }
}

void Requests(istream & is, Database & db)
{
    string result{};
    string s{};
    string command{};
    int y{0} , m{0}, d{0};
    string event{};
    while(getline(is, s))
    {
        command.clear();
        event.clear();
        y = 0; m = 0; d = 0;
        ParseLine(s, command, y,m,d, event);
        RunRequest(db, command, y,m,d, event);
    }
}
void RunRequest(Database & db,
                string const & command, int year, int month, int day, string const & event)
{
    Date date;
    try {
        if (command != "Print"){
            Date tmp(year, month, day);
            date = tmp;
        }
    } catch (string & s) {
//        cout << s;
        db.AddToLog(s);
    } catch(exception & ex){
        db.AddToLog(ex.what());
    } catch(...){
        db.AddToLog("Unknown exception");
    }


    if(command == "Add")
    {
        db.AddEvent(date,event);
    }else if(command == "Del")
    {
        if(event.empty())
        {
            db.DeleteDate(date);
        }else {
            db.DeleteEvent(date, event);
        }
    }else if(command == "Find")
    {
        db.Find(date);
    }else if(command == "Print")
    {
        db.Print();
    }else {
        db.AddToLog(string("Unknown command: ").append(command));
//        cout << "Unknown command: " << command;
    }
}

}
