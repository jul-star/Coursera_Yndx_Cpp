#pragma once
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

namespace white::w3 {

void ex_01(std::vector<int> &v)
{
    sort(begin(v), end(v),
         [](int x, int y)->bool{ return abs(x)<abs(y);});
}

}
