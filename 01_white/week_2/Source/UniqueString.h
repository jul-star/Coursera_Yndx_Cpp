#pragma once
#include <string>
#include <vector>

namespace white {

class UniqueString
{
public:
    UniqueString();
    static size_t CountUnique(std::vector<std::string> const  &v);
    static std::vector<std::string> ReadInput(std::istream &os);
};
}

