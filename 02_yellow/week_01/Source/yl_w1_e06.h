#pragma once
#include <vector>
#include <map>
#include <utility>
#include <exception>

using namespace ::std;

namespace yellow::w1::e06 {

template <typename Key, typename Value>
Value & GetRefStrict(map<Key, Value> & m, Key k)
{
    if(m.find(k) != m.end())
    {
        return m.at(k);
    }else{
        throw runtime_error("Wrong key.");
    }
}


}
