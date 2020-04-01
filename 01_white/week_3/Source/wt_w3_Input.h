#pragma once
#include <iostream>
#include <vector>

namespace white::w3 {
class Input
{
public:
    Input()=delete;
    static std::vector<int> ReadVector(std::istream & is);
};

}
