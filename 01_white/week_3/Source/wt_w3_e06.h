#pragma once
#include <map>
#include <string>
#include <utility>
#include <sstream>
#include <vector>
#include <set>

using namespace std;
namespace white::w3
{
class ReversibleString
{
private:
    string s;
public:
    explicit ReversibleString(const char *c):s(c){}
    string Reverse()
    {
        string t(s);
        s.clear();
        for(auto i = t.rbegin(); i!=t.rend();++i)
        {
            s.push_back(*i);
        }
        return s;
    }
    string ToString()
    {
        return s;
    }
};
}
