//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

#include <utility>

bool TaskService::postponeTask(TaskDTO &task, time_t dueDate) {
  TaskEntity entity = dto_convertor_.convert(task);
  return storage_.postponeTask(entity, dueDate);
}

bool TaskService::addTask(std::string taskName, time_t date, Task::Priority priority, std::string label) {
  return storage_.addTask(taskName, date, priority, label);
}

bool TaskService::deleteTask(TaskDTO &task) {
  TaskEntity entity = dto_convertor_.convert(task);
  return storage_.deleteTask(entity);
}

bool TaskService::completeTask(TaskDTO &task) {
  TaskEntity entity = dto_convertor_.convert(task);
  return storage_.completeTask(entity);
}

bool TaskService::addSubTaskToParent(TaskDTO &parent, std::string taskName, time_t date,
                                     Task::Priority priority,
                                     std::string label) {
  TaskEntity entity = dto_convertor_.convert(parent);
  if (storage_.addSubTaskToParent(entity, taskName, date, priority, label).has_value())
    return true;
  return false;
}

bool TaskService::addTask(Task &task) {
  return storage_.addTask(task);
}

bool TaskService::addSubTaskToParent(TaskDTO &parent, Task &task) {
  TaskEntity entity = dto_convertor_.convert(parent);
  if (storage_.addSubTaskToParent(entity, task).has_value())
    return true;
  return false;
}

std::vector<TaskDTO> TaskService::showAllByPriority() {
  return dto_convertor_.convert(storage_.showAllByPriority());
}

std::vector<TaskDTO> TaskService::showAllByLabel() {
  return dto_convertor_.convert(storage_.showAllByLabel());
}

std::vector<TaskDTO> TaskService::showAllByDate() {
  return dto_convertor_.convert(storage_.showAllByDate());
}

std::vector<TaskDTO> TaskService::showTodayByPriority() {
  return dto_convertor_.convert(storage_.showTodayByPriority());
}

std::vector<TaskDTO> TaskService::showTodayByLabel() {
  return dto_convertor_.convert(storage_.showTodayByLabel());
}

std::vector<TaskDTO> TaskService::showDueDateByPriority(time_t date) {
  return dto_convertor_.convert(storage_.showDueDateByPriority(date));
}

std::vector<TaskDTO> TaskService::showDueDateByLabel(time_t date) {
  return dto_convertor_.convert(storage_.showDueDateByLabel(date));
}

std::vector<TaskDTO> TaskService::showDueDateByDate(time_t date) {
  return dto_convertor_.convert(storage_.showDueDateByDate(date));
}

std::optional<std::vector<TaskDTO>> TaskService::getSubtasks(TaskID id) {
  auto it = storage_.getSubtasks(id);
  if (it.has_value()) {
    std::vector<std::shared_ptr<TaskEntity>> vector=it.value();
    std::vector<TaskDTO> dtos;
    for(auto i=vector.begin();i!=vector.end();i++) {
      dtos.push_back(dto_convertor_.convert(i->operator*()));
    }
    return dtos;
  }
  return std::nullopt;
}

std::optional<TaskDTO> TaskService::getTask(TaskID id) {
  auto it = storage_.getTask(id);
  if (it.has_value()) {
    std::shared_ptr<TaskEntity> ptr = it.value();
    return dto_convertor_.convert(ptr.operator*());
  }
  return std::nullopt;
}






