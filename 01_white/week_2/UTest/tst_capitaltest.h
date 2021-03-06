#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Capital.h"

using namespace ::testing;
using namespace ::white;

namespace white::w2::ts  {
class wt_w2_e02: public testing::Test
{
public:
    wt_w2_e02(){}
    virtual ~wt_w2_e02() override {}
    static size_t CountryCapitalSize(Capital &c)
    {
        return c.CountryCapital.size();
    }
    static std::vector<std::string> Split(Capital &c, std::string const & s)
    {
        return c.Split(s);
    }

    static std::map<std::string, std::string> GetCountryCapital(Capital &c)
    {
        return c.CountryCapital;
    }
    static std::string ChangeCapital(Capital &c,
                                     std::string const &country, std::string const &capital)
    {
        return c.ChangeCapital(country, capital);
    }
    static std::string RenameCountry(Capital &c,
                                     std::string const &OldCountryName,
                                     std::string const &NewCountryName )
    {
        return c.RenameCountry(OldCountryName, NewCountryName);
    }

    static std::string About(Capital &c,
                             std::string const &country)
    {
        return c.About(country);
    }
    static std::string Dump(Capital &c){
        return c.Dump();
    }
    static void Query(Capital &c,
                      std::vector<std::string> const &input,
                      std::vector<std::string> &out)
    {
        return c.Query(input, out);
    }
    static std::vector<std::string>  RunQueries(Capital &c,
                                                std::vector<std::string>  const &input){
        return c.RunQueries(input);
    }

    // Test interface
private:
    void TestBody() override{}
};

TEST_F(wt_w2_e02, Empty)
{
    Capital c;
    EXPECT_EQ(wt_w2_e02::CountryCapitalSize(c), 0);
}

TEST_F(wt_w2_e02, Split)
{
    Capital c;
    {
        std::string s{"Hello world."};
        std::vector<std::string> actual = wt_w2_e02::Split(c, s);
        std::vector<std::string> expected{"Hello", "world."};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string s{"Hello"};
        std::vector<std::string> actual = wt_w2_e02::Split(c, s);
        std::vector<std::string> expected{"Hello"};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string s{""};
        std::vector<std::string> actual = wt_w2_e02::Split(c, s);
        std::vector<std::string> expected{};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string s{"a b c d e f"};
        std::vector<std::string> actual = wt_w2_e02::Split(c, s);
        std::vector<std::string> expected{"a", "b", "c", "d", "e", "f"};
        EXPECT_EQ(expected, actual);
    }
}

TEST_F(wt_w2_e02, RunQueries_1)
{
    Capital c;
    std::vector<std::string> input{
        "CHANGE_CAPITAL RussianEmpire Petrograd",
        "RENAME RussianEmpire RussianRepublic",
        "ABOUT RussianRepublic",
        "RENAME RussianRepublic USSR",
        "CHANGE_CAPITAL USSR Moscow",
        "DUMP"
    };
    std::vector<std::string> actual = wt_w2_e02::RunQueries(c, input);
    std::vector<std::string> expected{
        "Introduce new country RussianEmpire with capital Petrograd",
        "Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic",
        "Country RussianRepublic has capital Petrograd",
        "Country RussianRepublic with capital Petrograd has been renamed to USSR",
        "Country USSR has changed its capital from Petrograd to Moscow",
        "USSR/Moscow"
    };
    EXPECT_EQ(expected, actual);
}

TEST_F(wt_w2_e02, RunQueries_2)
{
    Capital c;
    std::vector<std::string> input{
        "RENAME FakeCountry FarFarAway",
        "ABOUT FarFarAway",
        "DUMP",
        "CHANGE_CAPITAL TsardomOfRussia Moscow",
        "CHANGE_CAPITAL TsardomOfRussia Moscow",
        "CHANGE_CAPITAL ColonialBrazil Salvador",
        "CHANGE_CAPITAL TsardomOfRussia SaintPetersburg",
        "RENAME TsardomOfRussia RussianEmpire",
        "CHANGE_CAPITAL RussianEmpire Moscow",
        "CHANGE_CAPITAL RussianEmpire SaintPetersburg",
        "CHANGE_CAPITAL ColonialBrazil RioDeJaneiro",
        "DUMP",
        "RENAME ColonialBrazil EmpireOfBrazil",
        "ABOUT RussianEmpire",
        "RENAME EmpireOfBrazil UnitedStatesOfBrazil",
        "CHANGE_CAPITAL RussianEmpire Petrograd",
        "RENAME RussianEmpire RussianRepublic",
        "RENAME RussianRepublic USSR",
        "CHANGE_CAPITAL USSR Moscow",
        "CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia",
        "RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil",
        "ABOUT RussianEmpire",
        "DUMP",
        "RENAME USSR USSR"
    };
    std::vector<std::string> actual = wt_w2_e02::RunQueries(c, input);
    std::vector<std::string> expected{
        "Incorrect rename, skip",
        "Country FarFarAway doesn't exist",
        "There are no countries in the world",
        "Introduce new country TsardomOfRussia with capital Moscow",
        "Country TsardomOfRussia hasn't changed its capital",
        "Introduce new country ColonialBrazil with capital Salvador",
        "Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg",
        "Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire",
        "Country RussianEmpire has changed its capital from SaintPetersburg to Moscow",
        "Country RussianEmpire has changed its capital from Moscow to SaintPetersburg",
        "Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro",
        "ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg",
        "Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil",
        "Country RussianEmpire has capital SaintPetersburg",
        "Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil",
        "Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd",
        "Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic",
        "Country RussianRepublic with capital Petrograd has been renamed to USSR",
        "Country USSR has changed its capital from Petrograd to Moscow",
        "Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia",
        "Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil",
        "Country RussianEmpire doesn't exist",
        "FederativeRepublicOfBrazil/Brasilia USSR/Moscow",
        "Incorrect rename, skip"
    };
    ASSERT_EQ(expected.size(), actual.size());
    for(size_t i =0; i< expected.size(); ++i)
    {
        EXPECT_EQ(expected.at(i), actual.at(i)) << i << ": "<< expected.at(i) << ", " <<  actual.at(i);
    }
}

TEST_F(wt_w2_e02, Query)
{
    Capital c;
    {
        std::vector<std::string> input{"CHANGE_CAPITAL", "Ghana", "Mongo"};
        std::vector<std::string> out;
        wt_w2_e02::Query(c, input, out);
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected {{"Ghana", "Mongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        std::vector<std::string> input{"RENAME", "Ghana", "Hana"};
        std::vector<std::string> out;
        wt_w2_e02::Query(c, input, out);
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected {{"Hana", "Mongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        std::vector<std::string> input{"ABOUT", "Hana"};
        std::vector<std::string> out;
        wt_w2_e02::Query(c, input, out);
        std::vector<std::string> actual(out);
        std::vector<std::string> expected {"Country Hana has capital Mongo"};
        EXPECT_EQ(expected, actual);
    }
    {
        std::vector<std::string> input{"DUMP"};
        std::vector<std::string> out;
        wt_w2_e02::Query(c, input, out);
        std::vector<std::string> actual(out);
        std::vector<std::string> expected {"Hana/Mongo"};
        EXPECT_EQ(expected, actual);
    }

}
TEST_F(wt_w2_e02, ChangeCapital)
{
    Capital c;
    {
        wt_w2_e02::ChangeCapital(c, "Ghana", "Mongo");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Ghana", "Mongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        wt_w2_e02::ChangeCapital(c, "Ghana", "Bongo");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Ghana", "Bongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        wt_w2_e02::ChangeCapital(c, "Ghana", "Bongo");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Ghana", "Bongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        wt_w2_e02::ChangeCapital(c, "Ghana", "Tongo");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Ghana", "Tongo"}};
        EXPECT_EQ(expected, actual);
    }
}

TEST_F(wt_w2_e02, RenameCountry)
{
    Capital c;
    wt_w2_e02::ChangeCapital(c, "Ghana", "Tongo");
    {
        wt_w2_e02::RenameCountry(c, "Ghana", "Hana");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Hana", "Tongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        wt_w2_e02::RenameCountry(c, "Hana", "Zana");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Zana", "Tongo"}};
        EXPECT_EQ(expected, actual);
    }
    {
        wt_w2_e02::RenameCountry(c, "Zana", "Ghana");
        std::map<std::string, std::string> actual = wt_w2_e02::GetCountryCapital(c);
        std::map<std::string, std::string> expected{{"Ghana", "Tongo"}};
        EXPECT_EQ(expected, actual);
    }
}

TEST_F(wt_w2_e02, About)
{
    Capital c;
    wt_w2_e02::ChangeCapital(c, "Ghana", "Tongo");
    wt_w2_e02::ChangeCapital(c, "Russia", "Moscow");
    wt_w2_e02::ChangeCapital(c, "China", "Pekin");
    {
        std::string actual = wt_w2_e02::About(c,"Ghana");
        std::string expected{"Country Ghana has capital Tongo"};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string actual = wt_w2_e02::About(c,"Russia");
        std::string expected{"Country Russia has capital Moscow"};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string actual = wt_w2_e02::About(c,"China");
        std::string expected{"Country China has capital Pekin"};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string actual = wt_w2_e02::About(c,"Ura");
        std::string expected{"Country Ura doesn't exist"};
        EXPECT_EQ(expected, actual);
    }
    {
        std::string actual = wt_w2_e02::About(c,"");
        std::string expected{"Country  doesn't exist"};
        EXPECT_EQ(expected, actual);
    }
}

TEST_F(wt_w2_e02, Dump)
{
    Capital c;
    wt_w2_e02::ChangeCapital(c, "Ghana", "Tongo");
    wt_w2_e02::ChangeCapital(c, "Russia", "Moscow");
    wt_w2_e02::ChangeCapital(c, "China", "Pekin");
    {
        std::string actual = wt_w2_e02::Dump(c);
        std::string expected{"China/Pekin Ghana/Tongo Russia/Moscow"};
        EXPECT_EQ(expected, actual);
    }
}

}

