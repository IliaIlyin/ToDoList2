//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_STORAGE_H_
#define TODOLIST_MODEL_STORAGE_H_
#include<unordered_map>
#include"TaskEntity.h"
#include"HashTaskID.h"
class Storage {
 public:
  bool addTask(TaskEntity &task_entity);
  bool deleteTask(TaskEntity &task_entity);
  TaskEntity getTask(TaskEntity &task_entity);

 public:
  bool addSubTaskToParent(TaskEntity &parent, TaskEntity &task_entity);

 public:
  bool postponeTask(TaskEntity &task, time_t dueDate);
  bool completeTask(TaskEntity &task);

 private:
  std::unordered_map<TaskID, TaskEntity, HashTaskID> tasks_;
};

#endif //TODOLIST_MODEL_STORAGE_H_