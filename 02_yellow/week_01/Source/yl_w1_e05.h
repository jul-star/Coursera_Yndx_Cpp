#pragma once
#include <vector>
#include <map>
#include <utility>

using namespace ::std;

namespace yellow::w1::e05 {
template <typename T>
vector<T> Sqr(vector<T> & v);
template <typename Key, typename Value>
map<Key, Value>  Sqr(map<Key, Value> & m);
template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> &p);
template <typename First, typename Second>
pair<First, Second> operator*(pair<First, Second> &l, pair<First, Second> &r);

template <typename T>
vector<T> Sqr(vector<T> & v)
{
    for(auto & t: v)
    {
        t = t*t;
    }
    return v;
}

template <typename Key, typename Value>
map<Key, Value>  Sqr(map<Key, Value> & m)
{
    for(auto &[key, value]: m)
    {
        m[key] = value*value;
    }
    return m;
}

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> &p)
{
    p.first = p.first*p.first;
    p.second = p.second*p.second;
    return p;
}

template <typename First, typename Second>
pair<First, Second> operator*(pair<First, Second> &l, pair<First, Second> &r)
{
    return make_pair(l.first*r.first, l.second*r.second);
}

}
