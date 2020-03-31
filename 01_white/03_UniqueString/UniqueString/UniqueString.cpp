#include "UniqueString.h"
#include <set>
#include <iostream>
#include <sstream>

namespace white {

UniqueString::UniqueString()
{
}

size_t UniqueString::CountUnique(const std::vector<std::string> &v)
{
    std::set<std::string> s;
    for (auto & item: v)
    {
        s.insert(item);
    }
    return s.size();
}

std::vector<std::string> UniqueString::ReadInput(std::istream & os)
{
    std::vector<std::string> out;
    int n;
    os >> n;
    if ( n < 0 )
        return out;
    size_t l = static_cast<size_t>(n);
    std::string line;
    for(size_t i=0; i<l; ++i)
    {
        std::getline(os, line);
        std::stringstream ss;
        ss << line;
        std::string word;
        while(std::getline(ss, word, ' '))
        {
            out.push_back(word);
            if (out.size() >= l){
                break;
            }
        }
        if (out.size() >= l){
            break;
        }

    }
    return  out;
}

}
