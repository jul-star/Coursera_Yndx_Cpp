#include "Anagram.h"
#include <cmath>

using namespace std;
namespace white {
Anagram::Anagram()
{
}

int Anagram::CountWords(const std::string &s)
{
    map<char,int> ch = GetMap(s);
    size_t letters = ch.size();
    size_t length = s.size();
    size_t d = length-letters+1;
//    int sum=0;
//    for(int i=1;i<length;++i)
//    {
//        d = (letters-i)
//        sum += tgamma(letters+1)/(tgamma(i+1)*tgamma(letters-1+1));
//    }
    //Wan't compiles with -Werror flag in .pro file!
//    int i{2'000'000'000};
//    size_t t{1'000'000'000};
//    int j = i+t;
//    bool c = (i<t);

    return tgamma(length+1)/tgamma(d+1);
}

bool Anagram::IsAnagramm(const string &a, const string &b)
{
    map<char,int> am = GetMap(a);
    map<char,int> bm = GetMap(b);
    return am == bm;
//    for(auto const &[k,v]: am )
//    {
//        if(bm.find(k)!=bm.end())
//        {
//            if(bm.at(k) != am.at(k)){
//                return false;
//            }
//        }else{
//            return false;
//        }
//    }
//    return true;
}
map<char,int> Anagram::GetMap(const string &s)
{
   map<char,int> r;
   for(char const &c: s)
   {
       ++r[c];
   }
   return r;
}




}
