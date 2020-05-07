#pragma once
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace ::std;

namespace yellow::w1 {

vector<int> ex_01(istream & is)
{
    int days{0};
    is >> days;
    vector<int> temperature(days);
    int t{0};
    int sum{0};
    for(int d=0; d< days; ++d)
    {
        is >> t;
        sum += t;
        temperature[d] = t;
    }
    int mean{sum/days};
    vector<int> res;
    for(int d=0; d< days; ++d)
    {
        if(temperature[d]>mean)
        {
            res.push_back(d);
        }
    }
    return res;
}

}
