#pragma once
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace ::std;

namespace yellow::w1 {
struct Block{
    int Width;
    int Height;
    int Deep;
};

int ex_02(istream & is)
{
    int number{0};
    is >> number;

    vector<int> density(number);
    for(int d=0; d < number; ++d)
    {
       is >> density[d];
    }

    vector<Block> blocks(number);
    int sum{0};
    for(int d=0; d < number; ++d)
    {
        Block b;
        is >> b.Width >> b.Height >> b.Deep;
        sum += density[d]*b.Width*b.Height*b.Deep;
        blocks[d] = b;
    }

    return sum;
}

}
