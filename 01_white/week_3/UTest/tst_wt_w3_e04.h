#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e04.h>

using namespace testing;
using namespace white::w3;

namespace white::w3::ts  {
class wt_w3_e04: public Test{
public:
    wt_w3_e04(){}
};


TEST_F(wt_w3_e04, Sort_01)
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    vector<string> actual_01;
    for (int year : {1900, 1965, 1990}) {
        actual_01.push_back(person.GetFullName(year));
    }
    std::vector<std::string> expected_01{ "Incognito",
                                          "Polina with unknown last name",
                                          "Polina Sergeeva"
                                        };
    EXPECT_EQ(expected_01, actual_01);

    vector<string> actual_02;
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        actual_02.push_back(person.GetFullName(year));
    }
    std::vector<std::string> expected_02{ "Polina Sergeeva",
                                          "Appolinaria Sergeeva"};
    EXPECT_EQ(expected_02, actual_02);

    vector<string> actual_03;
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        actual_03.push_back(person.GetFullName(year));
    }
    std::vector<std::string> expected_03{"Polina Volkova",
                                         "Appolinaria Volkova"};
    EXPECT_EQ(expected_03, actual_03);
}

}
