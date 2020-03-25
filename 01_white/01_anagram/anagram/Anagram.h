#pragma once
#include <string>
#include <map>

namespace white {
class Anagram
{
public:
    Anagram();
    static int CountWords(std::string const & s);
    static bool IsAnagramm(std::string const &a, std::string const &b);
protected:
   static std::map<char, int> GetMap(const std::string &s);
};
}
