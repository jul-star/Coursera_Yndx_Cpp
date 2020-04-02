#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

namespace white::w3
{
std::string ex_02_tolower(std::string const &a)
{
    std::string res(a);
    for(size_t i = 0; i<res.size(); ++i)
    {
        res[i] = static_cast<char>(std::tolower(res[i]));
    }
    return res;
}

bool ex_02_helper(std::string const &a, std::string const &b)
{
    return ex_02_tolower(a) < ex_02_tolower(b);
}
void ex_02(std::vector<std::string> &v)
{
    return sort(begin(v), end(v),ex_02_helper);
}
}
