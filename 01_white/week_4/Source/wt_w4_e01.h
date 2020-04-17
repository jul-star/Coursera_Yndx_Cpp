#pragma once
#include <string>
using namespace ::std;

namespace white::w4 {
struct Specialization{
    string value;
    explicit Specialization(const char * s):value(s){}
};
struct Course{
    string value;
    explicit Course(const char * c):value(c){}
};
struct Week{
    string value;
    explicit Week(const char * w):value(w){}
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    explicit LectureTitle(Specialization const & s,
                          Course const & c,
                          Week const & w):
        specialization(s.value),
        course(c.value),
        week(w.value)
    {

    }
};



}
