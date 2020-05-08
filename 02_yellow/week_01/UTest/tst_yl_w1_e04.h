#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <yl_w1_e04.h>
#include <vector>

using namespace ::std;
using namespace ::yellow::w1::e04;
using namespace ::testing;

namespace yellow::w1::ts  {
class yl_w1_e03_t:public ::testing::Test{

};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

TEST_F(yl_w1_e03_t, TaskInfo_00)
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
      tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    //expected:
//    Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//    Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//    Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
//    Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
//    Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
//    Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
}

TEST_F(yl_w1_e03_t, TaskInfo_01)
{

}

}



