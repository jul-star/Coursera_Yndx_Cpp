#include "Capital.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;


namespace white {
Capital::Capital()
{
}

Capital::~Capital()
{

}

void Capital::Print(vector<string> const &result)
{
    for(auto &s: result)
    {
        cout << s << '\n';
    }
}

vector<string> Capital::GetInput()
{
    int q{0};
    cin >> q;
    size_t length(0);
    if (q > 0){
        length = static_cast<size_t>(q);
    }
    vector<string> result(length);
    for (size_t i=0; i<length; ++i)
    {
        std::string s;
        std::getline(cin, s);
        result[i] = s;
    }
    return result;
}
void Capital::Run()
{
    vector<string>  input = GetInput();
    vector<string> result = RunQueries(input);
    Print(result);
}
vector<string>  Capital::RunQueries(vector<string>  const &input)
{
    vector<string> result;
    for(auto &s: input)
    {
        Query(Split(s), result);
    }
    return result;
}

std::vector<std::string> Capital::Split(std::string const & s)
{
    vector<string> items;
    char delim(' ');
    string item;
    istringstream iss(s);
    while(getline(iss, item, delim))
    {
        items.emplace_back(item);
    }
    return items;
}

void Capital::Query(const std::vector<string> &input, std::vector<string> &out)
{
    if (input.empty()){
        return;
    }

    string tmp;
    if (input.at(0) == "CHANGE_CAPITAL" && input.size() == 3){
        tmp = ChangeCapital(input.at(1), input.at(2));
    } else if(input.at(0) == "RENAME" && input.size() == 3){
        tmp = RenameCountry(input.at(1), input.at(2));
    } else if(input.at(0) == "ABOUT" && input.size() == 2){
        tmp = About(input.at(1));
    }else if(input.at(0) == "DUMP"){
        tmp = Dump();
    }
    if (!tmp.empty()){
        out.push_back(tmp); }
}

std::string Capital::ChangeCapital(const string &country, const string &capital)
{
//    Introduce new country country with capital new_capital, если страны country раньше не существовало;
//    Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
//    Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital,
//    название которой не совпадает с названием new_capital.
    std::stringstream out;
    if (CountryCapital.find(country) != CountryCapital.end()) //find
    {
        if (CountryCapital.at(country) == capital)
        {
            out << "Country " << country  <<" hasn't changed its capital";
        } else{
           out << "Country " << country << " has changed its capital from " << CountryCapital.at(country) << " to " << capital;
        }
    } else {
        out << "Introduce new country " << country << " with capital " << capital;
    }
    CountryCapital[country] = capital;
    return out.str();
}

std::string Capital::RenameCountry(const string &OldCountryName, const string &NewCountryName)
{
    // Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
    std::stringstream out;
    if(OldCountryName != NewCountryName  &&
            CountryCapital.find(OldCountryName) != CountryCapital.end() &&
            CountryCapital.find(NewCountryName) == CountryCapital.end()) // find
    {
        string Capital = CountryCapital.at(OldCountryName);
        CountryCapital.erase(OldCountryName);
        CountryCapital[NewCountryName] = Capital;
        out << "Country " << OldCountryName << " with capital " << Capital << " has been renamed to "  << NewCountryName;
    } else {
        out << "Incorrect rename, skip";
    }
    return out.str();
}

string Capital::About(const string &country)
{
    std::stringstream out;
    if (CountryCapital.find(country) != CountryCapital.end()){
       out << "Country " << country << " has capital " << CountryCapital.at(country);
    } else{
       out << "Country " << country << " doesn't exist";
    }
    return out.str();
}

string Capital::Dump()
{
    if (CountryCapital.empty())
    {
        return string("There are no countries in the world");
    }
    size_t i = 0;
    stringstream out;
    for(auto & item: CountryCapital)
    {
        out << item.first << "/" <<  item.second;
        ++i;
        if (i < CountryCapital.size()){
            out << " ";
        }
    }
    return out.str();
}

}

