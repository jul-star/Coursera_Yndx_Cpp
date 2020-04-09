#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e05.h>

using namespace testing;
using namespace white::w3;

namespace white::w3::ts  {
class wt_w3_e05: public Test{
public:
    wt_w3_e05(){}
};


TEST_F(wt_w3_e05, Sort_01)
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

TEST_F(wt_w3_e05, GetFullNameWithHistory_01)
{
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    vector<string> actual;
    actual.push_back(person.GetFullNameWithHistory(1940));

    std::vector<std::string> expected{ "Incognito",
                                          "Polina with unknown last name",
                                          "Polina Sergeeva"
                                        };
    EXPECT_EQ(expected, actual);

}

TEST_F(wt_w3_e05, GetFullNameWithHistory_01)
{
    Person person;
    {
    vector<string> actual;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
      actual.push_back(person.GetFullNameWithHistory(1940));
    }
    std::vector<std::string> expected{};
    EXPECT_EQ(expected, actual);
    }

//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//      cout << person.GetFullNameWithHistory(year) << endl;
//    }

//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//      cout << person.GetFullNameWithHistory(year) << endl;
//    }

//    person.ChangeFirstName(1990, "Polina");
//    person.ChangeLastName(1990, "Volkova-Sergeeva");
//    cout << person.GetFullNameWithHistory(1990) << endl;

//    person.ChangeFirstName(1966, "Pauline");
//    cout << person.GetFullNameWithHistory(1966) << endl;

//    person.ChangeLastName(1960, "Sergeeva");
//    for (int year : {1960, 1967}) {
//      cout << person.GetFullNameWithHistory(year) << endl;
//    }

//    person.ChangeLastName(1961, "Ivanova");

//    vector<string> actual = person.GetFullNameWithHistory(1940);

//    std::vector<std::string> expected{ "Incognito",
//                                          "Polina with unknown last name",
//                                          "Polina Sergeeva"
//                                        };
//    EXPECT_EQ(expected, actual);

}

}
