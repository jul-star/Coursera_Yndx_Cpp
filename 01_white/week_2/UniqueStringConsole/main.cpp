#include <iostream>
#include <UniqueString.h>
#include <vector>
#include <string>
#include <sstream>
#include <istream>

using namespace white;
using namespace std;

int main()
{
    vector<string> v = UniqueString::ReadInput(std::cin);
    cout << "Size of vector: " << v.size() << '\n';
    for(auto const & item: v)
    {
        cout << item  << '\n';
    }

    return 0;
}
