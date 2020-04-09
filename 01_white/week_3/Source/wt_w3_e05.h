#pragma once
#include <map>
#include <string>
#include <utility>
#include <sstream>
#include <vector>

using namespace std;
namespace white::w3
{
class Person {
private:
    //    map<int, pair<string, string>> history;
    map<int, string> first;
    map<int, string> last;
public:
    /*!
   * \brief добавить факт изменения имени в год
   * \param year
   * \param first_name
   */
    void ChangeFirstName(int year, const string& first_name) {
        first[year]= first_name;
    }
    /*!
   * \brief добавить факт изменения фамилии в год
   * \param year
   * \param last_name
   */
    void ChangeLastName(int year, const string& last_name) {
        last[year]= last_name;
    }

    /*!
   * \brief GetFullName
   * \param year
   * \return получить имя и фамилию по состоянию на конец года
   */
    string GetFullName(int year) {
        return FullName(LatestRecord(year, first), LatestRecord(year, last));
    }
    /*!
     * \brief получить все имена и фамилии по состоянию на конец года
     * \param year
     * \return
     */
    string GetFullNameWithHistory(int year) {
        return {};
    }
private:
    string FullName(string const &fname, string const & lname)
    {
        stringstream ss;
        if (fname.empty() && lname.empty())
        {
            return "Incognito";
        }
        if (fname.empty() )
        {
            ss << lname << " with unknown first name";
        } else if(lname.empty())
        {
            ss << fname << " with unknown last name";
        } else{
            ss << fname << " " << lname;
        }
        return ss.str();
    }

    string LatestRecord(int year, map<int, string> const & m){
        if(m.find(year) != m.end())
        {
            return m.at(year);
        }
        int LeftClosestYear=-1;
        string result{};
        for(map<int, string>::const_iterator p = m.begin();
            p != m.end() && p->first < year; ++p)
        {
                if(LeftClosestYear < p->first)
                {
                    LeftClosestYear = p->first;
                    result = p->second;
                }
        }
        return result;
    }
};

}
