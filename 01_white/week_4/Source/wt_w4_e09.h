#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

using namespace ::std;

namespace white::w4::e09
{
void EnsureEqual(const string& left, const string& right)
{
 if (left != right)
 {
     string err(left);
     err.append(" != ").append(right);
     throw runtime_error(err);
 }
}
}




