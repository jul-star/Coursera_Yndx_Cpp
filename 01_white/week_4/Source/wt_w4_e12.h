#pragma once
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>

using namespace ::std;
namespace white::w4::ts {
string AskTimeServer();
}
namespace white::w4::e12
{

class TimeServer {
public:
    /*
* он должен вызвать функцию *AskTimeServer*,
записать её результат в поле *LastFetchedTime* и вернуть значение этого поля;

* если *AskTimeServer* выбросила исключение *system_error*,
метод *GetCurrentTime* должен его поймать и вернуть текущее значение поля *LastFetchedTime*.
Таким образом мы скрываем от пользователя сетевые проблемы, возвращая значение,
которое было получено при последнем успешном обращении к серверу;

* если *AskTimeServer* выбросила другое исключение,
метод *GetCurrentTime* должен пробросить его дальше,
потому что в рамках класса *TimeServer* мы не знаем, как обрабатывать проблемы,
не связанные со сбоями сети.
*/
  string GetCurrentTime();
private:
  string LastFetchedTime = "00:00:00";

};
string TimeServer::GetCurrentTime()
{
    try {
        LastFetchedTime = ::white::w4::ts::AskTimeServer();
    } catch (system_error &se) {
        return  LastFetchedTime;
    }catch(exception &ex)
    {
        throw  ex;
    }catch(...)
    {
        throw "Unknown exception";
    }

    return  LastFetchedTime;
}


}




