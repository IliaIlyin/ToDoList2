//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_CONTEXTS_INPUTCONTEXT_H_
#define TODOLIST_CLI_CONTEXTS_INPUTCONTEXT_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "API/TaskID.h"
#include "API/Task.h"
/*
 * class that contains the information needed to create task
 * Context for InputStateMachine
 * @see InputStateMachine
 *
 * @see Task
 *
 * @author Ilya Ilyin
 */
class InputContext {

 public:
  void setId(const TaskID &id);
  void setName(const std::string &name);
  void setDate(const boost::gregorian::date &date);
  void setPriority(Task::Priority priority);
  void setLabel(const std::string &label);

 public:
  const std::string &getName() const;
  const boost::gregorian::date &getDate() const;
  Task::Priority getPriority() const;
  const std::string &getLabel() const;
  const TaskID &getId() const;

 private:
  std::string name_;
  boost::gregorian::date date_;
  Task::Priority priority_;
  std::string label_;
  TaskID id_;
};

#endif //TODOLIST_CLI_CONTEXTS_INPUTCONTEXT_H_
