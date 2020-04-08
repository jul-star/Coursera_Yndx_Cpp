#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
namespace white::w3
{
class SortedStrings {
public:
    /*!
    * \brief добавить строку s в набор
    * \param s
    */
  void AddString(const string& s) {
    v.push_back(s);
  }
  /*!
   * \brief получить набор из всех добавленных строк
   * в отсортированном порядке
   * \return
   */
  vector<string> GetSortedStrings() {
      sort(begin(v), end(v));
      return  v;
  }
private:
  vector<string> v;
};

}
