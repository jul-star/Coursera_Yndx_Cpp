#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

struct sStop{
    string stop;
    int number;
};
using tBus = string;
using tBus = string;
using tBuses = vector<tBus>;
using tStop = string;
using tStops = map<sStop, tBuses>;
using tBusRoute = map<tBus, vector<sStop>>;
using tBusTrunsfer = map<tBus, tStops>;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    int qtype;
    is >> qtype;
    q.type = static_cast<QueryType>(qtype);
    is >> q.bus;
    is >> q.stop;
    int num;
    is >> num;
    string Name;
    for(int i=0; i<num; ++i)
    {
        is >> Name;
        q.stops.push_back(Name);
    }
    return is;
}

struct BusesForStopResponse {
    // Наполните полями эту структуру
    tStops b4sr;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    for(auto const & s: r.b4sr)
    {
        os << s.first.stop << endl;
        bool first = true;
        for(auto const &b: s.second )
        {
            if(!first)
            {
                os << ' ';
                first = false;
            }
            os << b;
        }
    }
    return os;
}



struct StopsForBusResponse {
    // Наполните полями эту структуру

    tBusTrunsfer bt;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{

    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру

    map<tBus, tStops> b;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    for(auto const & bs: r.b)
    {
        auto const & bus = bs.first;
        os << bus << endl;
        bool first = true;
        auto const & stops = bs.second;
        for(auto const &s: stops )
        {
            if(!first)
            {
                os << ' ';
                first = false;
            }
            os << s.first.stop;
        }
    }
    return os;
}

class BusManager {
private:
    tBusRoute BusRoute;
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        // Реализуйте этот метод
        vector<sStop> route;
        int count{0};
       for(auto const & stop: stops)
       {
           ++count;
           route.emplace_back(stop, count);
       }
       //TODO: start from here.
       BusRoute[bus] = route;
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        // Реализуйте этот метод
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        // Реализуйте этот метод
    }

    AllBusesResponse GetAllBuses() const {
        // Реализуйте этот метод
    }
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}

