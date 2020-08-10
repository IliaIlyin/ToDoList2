//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_MODEL_ALLDATASTORAGE_H_
#define TODOLIST_MODEL_ALLDATASTORAGE_H_

#include "Views/ViewService.h"
#include "StorageService.h"
#include "boost/date_time/gregorian/gregorian.hpp"

class AllDataStorage {

public:
    bool
    addTask(std::string taskName, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
            Task::Priority priority = Task::Priority::NONE, std::string label = "");

    std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent,
                                                                  std::string taskName,
                                                                  boost::gregorian::date date = boost::gregorian::date(
                                                                          boost::gregorian::min_date_time),
                                                                  Task::Priority priority = Task::Priority::NONE,
                                                                  std::string label = "");

    bool addTask(Task &task);

    std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, Task &task);

    std::optional<std::shared_ptr<TaskEntity>> getTask(TaskID id);

    std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubtasks(TaskID id);

public:
    bool postponeTask(TaskEntity &task, boost::gregorian::date dueDate);

    bool deleteTask(TaskEntity &task);

    bool completeTask(TaskEntity &task);

public:
    std::vector<std::weak_ptr<TaskEntity>> showAllByPriority();

    std::vector<std::weak_ptr<TaskEntity>> showAllByLabel();

    std::vector<std::weak_ptr<TaskEntity>> showAllByDate();

    std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority();

    std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel();

    std::vector<std::weak_ptr<TaskEntity>>
    showDueDateByPriority(boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time));

    std::vector<std::weak_ptr<TaskEntity>>
    showDueDateByLabel(boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time));

    std::vector<std::weak_ptr<TaskEntity>>
    showDueDateByDate(boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time));

private:
    ViewService view_service_;
    StorageService storage_service_;
};

#endif //TODOLIST_MODEL_ALLDATASTORAGE_H_
