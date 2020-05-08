#pragma once
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace ::std;

namespace yellow::w1::e04 {
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
    map<string, TasksInfo> vPersonTask;
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
      return vPersonTask.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person)
  {
      ++vPersonTask[person][TaskStatus::NEW];
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count)
  {
      return {};
  }
};

}
