#pragma once
#include <map>
#include <string>
#include <utility>
#include <sstream>

using namespace std;
namespace white::w3
{
class Person {
private:
    map<int, pair<string, string>> history;
public:
    /*!
   * \brief добавить факт изменения имени на first_name в год year
   * \param year
   * \param first_name
   */
    void ChangeFirstName(int year, const string& first_name) {
        if(history.find(year) != history.end())
        {
            pair<string, string> p = history.at(year);
            p.first = first_name;
            history[year]= p;

        }else{
            pair<string, string> p = LeftestRecord(year);
            string first(first_name);
            string second{p.second};
            history[year]= make_pair(first, second);
        }
    }
    /*!
   * \brief добавить факт изменения фамилии на last_name в год year
   * \param year
   * \param last_name
   */
    void ChangeLastName(int year, const string& last_name) {
        if(history.find(year) != history.end())
        {
            pair<string, string> p = history.at(year);
            p.second = last_name;
            history[year]= p;

        }else{
            pair<string, string> p = LeftestRecord(year);
            string first{p.first};
            string second{last_name};
            history[year]= make_pair(first, second);
        }
    }


    /*!
   * \brief GetFullName
   * \param year
   * \return получить имя и фамилию по состоянию на конец года year
   */
    string GetFullName(int year) {
        if(history.find(year) != history.end())
        {
            pair<string, string> p = history.at(year);
            return FullName(p);
        }
        pair<string, string> p = LeftestRecord(year);
        return FullName(p);
    }
private:
    string FullName(pair<string, string> const & p)
    {
        stringstream ss;
        if (p.first.empty() && p.second.empty())
        {
            return "Incognito";
        }
        if (p.first.empty() )
        {
            ss << p.second << " with unknown first name";
        } else if(p.second.empty())
        {
            ss << p.first << " with unknown last name";
        } else{
            ss << p.first << " " << p.second;
        }
        return ss.str();
    }
    pair<string, string> LeftestRecord(int year)
    {
        int LeftClosestYear=-1;
        map<int, pair<string, string>>::const_iterator it= history.end();
        for(map<int, pair<string, string>>::const_iterator p = history.begin();
            p != history.end(); ++p)
        {
            if (p->first < year)
            {
                if(LeftClosestYear < p->first)
                {
                    LeftClosestYear = p->first;
                    it = p;
                }
            }
        }
        if (LeftClosestYear != -1)
        {
            return pair<string, string>(it->second);
        }
        return {};
    }
};

}
