//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_SHOW_SHOWTODAY_SHOWTODAYBYLABELCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SHOW_SHOWTODAY_SHOWTODAYBYLABELCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Commands/Show/ShowToday/ShowTodayByLabelCommand.h"

class ShowTodayByLabelCommandBuilder: public Builder  {
  std::shared_ptr<Command> buildCommand(std::shared_ptr<TaskService> service) override;

};

#endif //TODOLIST_CLI_BUILDERS_SHOW_SHOWTODAY_SHOWTODAYBYLABELCOMMANDBUILDER_H_
