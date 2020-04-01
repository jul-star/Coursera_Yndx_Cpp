#include "wt_w3_Input.h"

namespace white::w3 {

std::vector<int> Input::ReadVector(std::istream &is)
{
    int n{0};
    is >> n;
    if (n<0){
        return std::vector<int>();
    }
    size_t l = static_cast<size_t>(n);
    std::vector<int> res(l);
    int v{0};
    for(size_t i=0; i<l;++i)
    {
        is >> v;
        res[i] = v;
    }
    return  res;
}

}
