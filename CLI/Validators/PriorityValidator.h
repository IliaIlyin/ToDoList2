//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_PRIORITYVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_PRIORITYVALIDATOR_H_

#include "Validator.h"

class PriorityValidator : public Validator {
  CommandsValidator::ValidateResult validate(const std::string & str) override;

};

#endif //TODOLIST_CLI_VALIDATORS_PRIORITYVALIDATOR_H_