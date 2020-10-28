//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_ADDTASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_ADDTASKCOMMAND_H_

#include "API/Task.h"
#include "Command.h"
#include "Visitor.h"
#include "ClientInterface.h"
#include <memory>

class AddTaskCommand : public Command {

 public:
  AddTaskCommand(std::shared_ptr<ClientInterface> service, const Task &parent);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 public:
  bool getAddTaskResult() const;

 private:
  std::shared_ptr<ClientInterface> service_;
  Task parent_;
  bool addTaskResult_;
};

#endif //TODOLIST_CLI_COMMANDS_ADDTASKCOMMAND_H_
