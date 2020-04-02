#pragma once
#include <string>
#include <vector>
#include <map>

namespace ts {
class CapitalTest;
}
namespace white {
class Capital
{
private:
    std::map<std::string, std::string> CountryCapital;
public:
    Capital();
    ~Capital();    
    void Run();
protected:
    std::vector<std::string> RunQueries(const std::vector<std::string> &input);
    //!
    //! \brief Query
    //! \param s
    //! \details CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
    //! RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
    //! ABOUT country — вывод столицы страны country.
    //! DUMP — вывод столиц всех стран.
    //!
    void Query(std::vector<std::string> const &input, std::vector<std::string> &out);
    std::string ChangeCapital(std::string const &country, std::string const &capital);
    std::string RenameCountry(std::string const &OldCountryName, std::string const &NewCountryName );
    std::string About(std::string const &country);
    std::string Dump();
private:
    std::vector<std::string> Split(std::string const & s);
    void Print(const std::vector<std::string> &result);
    std::vector<std::string> GetInput();

private:
    friend class ts::CapitalTest;
};
}

