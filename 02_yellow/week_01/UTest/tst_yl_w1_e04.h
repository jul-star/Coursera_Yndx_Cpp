#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <yl_w1_e04.h>
#include <vector>
#include <string>
#include <sstream>

using namespace ::std;
using namespace ::yellow::w1::e04;
using namespace ::testing;

namespace yellow::w1::ts  {
class yl_w1_e04_t:public ::testing::Test{

};

string PrintTasksInfo(TasksInfo tasks_info) {
    stringstream ss;
    ss << tasks_info[TaskStatus::NEW] << " new tasks" <<
                                         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
                                         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
                                         ", " << tasks_info[TaskStatus::DONE] << " tasks are done";
    return ss.str();
}

TEST_F(yl_w1_e04_t, TaskInfo_00)
{
    TaskStatus status{TaskStatus::DONE};
    TaskStatus next_status = static_cast<TaskStatus>(static_cast<int>(status)+1);

    EXPECT_NE(TaskStatus::NEW, next_status) << "next: " << static_cast<int>(next_status);
    EXPECT_NE(TaskStatus::IN_PROGRESS, next_status) << "next: " << static_cast<int>(next_status);
    EXPECT_NE(TaskStatus::TESTING, next_status) << "next: " << static_cast<int>(next_status);
    EXPECT_NE(TaskStatus::DONE, next_status) << "next: " << static_cast<int>(next_status);
}

TEST_F(yl_w1_e04_t, TaskInfo_01)
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    string expIlia{"1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
    string actIlia = PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    EXPECT_EQ(expIlia, actIlia) << "actIlia: act: " << actIlia;
}

TEST_F(yl_w1_e04_t, TaskInfo_02)
{
    TeamTasks tasks;
    string person{"Ilia"};
    tasks.AddNewTask(person);
    {
        string expIlia{"1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        string actIlia = PrintTasksInfo(tasks.GetPersonTasksInfo(person));
        EXPECT_EQ(expIlia, actIlia) << "actIlia: act: " << actIlia;
    }

    TasksInfo updated_tasks, untouched_tasks;
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks(person, 1);

    {
        string expIlia{"0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        string actIlia = PrintTasksInfo(tasks.GetPersonTasksInfo(person));
        EXPECT_EQ(expIlia, actIlia) << "actIlia: act: " << actIlia;
    }
}

TEST_F(yl_w1_e04_t, TaskInfo_03)
{
    TeamTasks tasks;
    string person{"Ilia"};
    tasks.AddNewTask(person);
    tasks.AddNewTask(person);

    {
        string expIlia{"2 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        string actIlia = PrintTasksInfo(tasks.GetPersonTasksInfo(person));
        EXPECT_EQ(expIlia, actIlia) << "actIlia: act: " << actIlia;
    }

    TasksInfo updated_tasks, untouched_tasks;
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks(person, 1);

    {
        string expIlia{"1 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        string actIlia = PrintTasksInfo(tasks.GetPersonTasksInfo(person));
        EXPECT_EQ(expIlia, actIlia) << "actIlia: act: " << actIlia;
    }
}



TEST_F(yl_w1_e04_t, TaskInfo_11)
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }

    {
        //    cout << "Ilia's tasks: ";
        string expIlia{"1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        string actIlia = PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
        EXPECT_EQ(expIlia, actIlia) << "actIlia: act: " << actIlia;
    }

    {
        //    cout << "Ivan's tasks: ";
        string expIvan{"3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        string actIvan = PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
        EXPECT_EQ(expIvan, actIvan) << "Ivan's tasks: act: " << actIvan;
    }

    {
        TasksInfo updated_tasks, untouched_tasks;
        tie(updated_tasks, untouched_tasks) =
                tasks.PerformPersonTasks("Ivan", 2);
        //    cout << "Updated Ivan's tasks: ";
        string actIvanM =PrintTasksInfo(updated_tasks);
        string expIvanM{"0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        EXPECT_EQ(expIvanM, actIvanM) << "Updated Ivan's tasks: act: " << actIvanM;

        //        cout << "Untouched Ivan's tasks: ";
        string actIvanU = PrintTasksInfo(untouched_tasks);
        string expIvanU{"1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        EXPECT_EQ(expIvanU, actIvanU) << "Untouched Ivan's tasks: act: " << actIvanU;
    }

    {
        TasksInfo updated_tasks, untouched_tasks;
        tie(updated_tasks, untouched_tasks) =
                tasks.PerformPersonTasks("Ivan", 2);
        cout << "Updated Ivan's tasks: ";
        string actIvanM = PrintTasksInfo(updated_tasks);
        string expIvanM{"0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done"};
        EXPECT_EQ(expIvanM, actIvanM) << "Updated Ivan's tasks: act: " << actIvanM;

        cout << "Untouched Ivan's tasks: ";
        string actIvanU = PrintTasksInfo(untouched_tasks);
        string expIvanU{"0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done"};
        EXPECT_EQ(expIvanU, actIvanU) << "Untouched Ivan's tasks: act: " << actIvanU;
    }
    //expected:
    //    Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
    //    Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
    //    Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
    //    Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
    //    Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
    //    Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
}



}



