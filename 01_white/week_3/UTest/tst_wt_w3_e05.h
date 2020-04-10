#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w3_e05.h>

using namespace testing;
using namespace white::w3;

namespace white::w3::ts  {
class wt_w3_e05: public Test{
};

TEST_F(wt_w3_e05, GetFullNameWithHistory_01)
{
    Person2 person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    vector<string> actual;
    actual.push_back(person.GetFullNameWithHistory(1940));

    std::vector<std::string> expected{ "Evgeny (Eugene) Sokolov" };
    EXPECT_EQ(expected, actual);

}

TEST_F(wt_w3_e05, GetFullNameWithHistory_02)
{
    Person2 person;
    {
        vector<string> actual;
        person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1967, "Sergeeva");
        for (int year : {1900, 1965, 1990}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Incognito",
                                          "Polina with unknown last name",
                                          "Polina Sergeeva"};
        EXPECT_EQ(expected, actual);
    }

    {
        vector<string> actual;
        person.ChangeFirstName(1970, "Appolinaria");
        for (int year : {1969, 1970}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Polina Sergeeva",
                                          "Appolinaria (Polina) Sergeeva"};
        EXPECT_EQ(expected, actual);
    }

    {
        vector<string> actual;
        person.ChangeLastName(1968, "Volkova");
        for (int year : {1969, 1970}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Polina Volkova (Sergeeva)",
                                          "Appolinaria (Polina) Volkova (Sergeeva)"};
        EXPECT_EQ(expected, actual);
    }
    {
        vector<string> actual;
        person.ChangeFirstName(1990, "Polina");
        person.ChangeLastName(1990, "Volkova-Sergeeva");
        for (int year : {1990}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)"};
        EXPECT_EQ(expected, actual);
    }
    {
        vector<string> actual;
        person.ChangeFirstName(1966, "Pauline");

        for (int year : {1966}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Pauline (Polina) with unknown last name"};
        EXPECT_EQ(expected, actual);
    }
    {
        vector<string> actual;
        person.ChangeLastName(1960, "Sergeeva");
        for (int year : {1960, 1967}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Sergeeva with unknown first name",
                                          "Pauline (Polina) Sergeeva"};
        EXPECT_EQ(expected, actual);
    }

    {
        vector<string> actual;
        person.ChangeLastName(1961, "Ivanova");
        for (int year : { 1967}) {
            actual.push_back(person.GetFullNameWithHistory(year));
        }
        std::vector<std::string> expected{"Pauline (Polina) Sergeeva (Ivanova, Sergeeva)"};
        EXPECT_EQ(expected, actual);
    }

}

}
