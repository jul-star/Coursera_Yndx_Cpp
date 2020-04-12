#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e07.h>
#include <vector>
#include <string>

using namespace std;
using namespace ::testing;
using namespace white::w3;

namespace ts{
class wt_w3_e07: public Test{

};

TEST_F(wt_w3_e07, test_01)
{
    Person3 person("Polina", "Sergeeva", 1960);
    {
        vector<string> actual;
        for (int year : {1959, 1960}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        vector<string> expected{"No person",
                                "Polina Sergeeva"};
        EXPECT_EQ(expected, actual);
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    {
        vector<string> actual;
        for (int year : {1965, 1967}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        vector<string> expected{"Appolinaria (Polina) Sergeeva",
                                "Appolinaria (Polina) Ivanova (Sergeeva)"};
        EXPECT_EQ(expected, actual);
    }
}
}
