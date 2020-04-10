#pragma once
#include <map>
#include <string>
#include <utility>
#include <sstream>
#include <vector>

using namespace std;
namespace white::w3
{
class Person2 {
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
        if(LatestRecord(year, first) != first_name){
            first[year]= first_name;
        }
    }
    /*!
   * \brief добавить факт изменения фамилии в год
   * \param year
   * \param last_name
   */
    void ChangeLastName(int year, const string& last_name) {
        if(LatestRecord(year, last) != last_name){
            last[year]= last_name;
        }
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
        string fname = GetHistory(year, first);
        string lname = GetHistory(year, last);
        string res = BuildName(fname, lname);
        return res;
    }
private:
    string GetHistory(int year, map<int, string> const & m){
        vector<string> v;
        for(map<int, string>::const_iterator i = m.cbegin();
            i != m.cend() && i->first <= year; ++i)
        {
            v.push_back(i->second);
        }
        return BuildHistory(v);
    }
    string BuildName(string const & f, string const & l){
        if (f.empty() && l.empty())        {
            return "Incognito";
        }
        if (l.empty())        {
            return f  + " with unknown last name";
        }
        if(f.empty()){
            return l + " with unknown first name";
        }
        return f + " " + l;
    }

    string BuildHistory(vector<string> const &v)
    {
        if (v.empty())
        {
            return {};
        }
        string last{v.back()};
        string h{};
        size_t c{0};
        for(auto i = v.crbegin(); i != v.crend(); ++i)
        {
            if (c == 0)
            {
                ++c;
                continue;
            }
            h.append(*i);
            if (c < v.size()-1){
                h.append(", ");
            }
            ++c;
        }
        string res{last};
        if (!h.empty()){
            res.append(" (").append(h).append(")");
        }
        return res;
    }
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
