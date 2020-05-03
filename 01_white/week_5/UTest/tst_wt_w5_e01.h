#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <wt_w5_e01.h>
#include <string>
#include <sstream>


using namespace ::std;
using namespace ::testing;
using namespace ::white::w5;

namespace ts::wt::w5::e01 {
class wt_w5_e01: public Test{};

TEST_F(wt_w5_e01, t1)
{
    stringstream ss;
    ss << "Add 0-1-2 event1" << endl
       << "Add 1-2-3 event2" << endl
       <<     "Find 0-1-2" << endl
           <<   "Del 0-1-2" << endl
             <<   "Print";
    Database db;
    Requests(ss, db);
    vector<string> expected{"event1",
                            "Deleted 1 events",
                            "0001-02-03 event2"};
    vector<string> actual = db.Log();
    EXPECT_EQ(expected, actual);
}

TEST_F(wt_w5_e01, t2)
{
    stringstream ss;
    ss << "Add 0-13-32 event1";
    Database db;
    Requests(ss, db);
    vector<string> expected{"Month value is invalid: 13"};
    vector<string> actual = db.Log();
    EXPECT_EQ(expected, actual);
}

}
