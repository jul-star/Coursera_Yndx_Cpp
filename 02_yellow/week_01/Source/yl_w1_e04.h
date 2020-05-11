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

    int GetRefreshNumber(int number, int &task_count)
    {
        int toRefresh{0};
        if(number < task_count)
        {
            toRefresh = number;
            task_count -= number;
        }else{
            toRefresh = task_count;
            task_count = 0;
        }
        return toRefresh;
    }

    void RefreshTaskStatus(TasksInfo const & ti, TaskStatus status, TasksInfo & result, int & task_count)
    {
        if(ti.find(status) != ti.end())
        {
            result[status] = GetRefreshNumber(ti.at(status), task_count);
        }
    }

    void BuildWithNewStatus(TasksInfo const & delist, TaskStatus cur,
                            TasksInfo & new_status, TaskStatus next )
    {
        if (delist.find(cur) != delist.end())
        {
            new_status[next] = delist.at(cur);
        }
    }

    tuple<TasksInfo, TasksInfo> GetTasksToDelistAndWithNewStatus(TasksInfo & ti, int task_count)
    {
        if (task_count == 0)
        {
            return {};
        }
        TasksInfo ToDelist;
        TasksInfo WithNewStatus;

        RefreshTaskStatus(ti, TaskStatus::NEW, ToDelist, task_count);
        BuildWithNewStatus(ToDelist, TaskStatus::NEW, WithNewStatus, TaskStatus::IN_PROGRESS);
        if(task_count == 0){ return tie(ToDelist,WithNewStatus); }

        RefreshTaskStatus(ti, TaskStatus::IN_PROGRESS, ToDelist, task_count);
        BuildWithNewStatus(ToDelist, TaskStatus::IN_PROGRESS, WithNewStatus, TaskStatus::TESTING);
        if(task_count == 0){ return tie(ToDelist,WithNewStatus); }

        RefreshTaskStatus(ti, TaskStatus::TESTING, ToDelist, task_count);
        BuildWithNewStatus(ToDelist, TaskStatus::TESTING, WithNewStatus, TaskStatus::DONE);
        if(task_count == 0){ return tie(ToDelist,WithNewStatus); }

        RefreshTaskStatus(ti, TaskStatus::DONE, ToDelist, task_count);
        return tie(ToDelist,WithNewStatus);
    }

    int SubtractOldTask(TasksInfo & ti, TasksInfo const & delist, TaskStatus status)
    {
        int old{0};
        if(delist.find(status) != delist.end())
        {
            if(ti.find(status) == ti.end())
            {
                ti[status]=0;
            }
            old = ti.at(status) - delist.at(status);
            ti[status] = old;
        }
        return old;
    }
    TasksInfo GetOldTask(TasksInfo & ti, TasksInfo const & delist)
    {
        TasksInfo old;
        int vOld{0};
        vOld = SubtractOldTask(ti, delist, TaskStatus::NEW);
        if (vOld != 0) {old[TaskStatus::NEW] = vOld; vOld = 0;}

        vOld = SubtractOldTask(ti, delist, TaskStatus::IN_PROGRESS);
        if (vOld != 0) {old[TaskStatus::IN_PROGRESS] = vOld; vOld = 0;}

        vOld = SubtractOldTask(ti, delist, TaskStatus::TESTING);
        if (vOld != 0) {old[TaskStatus::TESTING] = vOld; vOld = 0;}

        vOld = SubtractOldTask(ti, delist, TaskStatus::DONE);
        if (vOld != 0) {old[TaskStatus::DONE] = vOld; }
        return old;
    }

    void Add(TasksInfo & ti, TasksInfo const & nw, TaskStatus status)
    {
        if(nw.find(status)!= nw.end())
        {
            if(nw.at(status) != 0)
            {
                ti[status] += nw.at(status);
            }
        }
    }

    void AddTaskWithNewStatus(TasksInfo & ti, TasksInfo const & nw)
    {
        Add(ti, nw, TaskStatus::NEW);
        Add(ti, nw, TaskStatus::IN_PROGRESS);
        Add(ti, nw, TaskStatus::TESTING);
        Add(ti, nw, TaskStatus::DONE);
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count)
    {
        if(task_count == 0 )
        {
            return {};
        }
        TasksInfo old;
        TasksInfo nw;
        TasksInfo delist;
        int tasks = task_count;
        if (vPersonTask.find(person) != vPersonTask.end())
        {
            TasksInfo ti = vPersonTask.find(person)->second;
            tie(delist, nw) = GetTasksToDelistAndWithNewStatus(ti, tasks);
            old = GetOldTask(ti, delist);
            AddTaskWithNewStatus(ti, nw);
        }

        return tie<TasksInfo, TasksInfo>(nw, old);
    }
};

}
