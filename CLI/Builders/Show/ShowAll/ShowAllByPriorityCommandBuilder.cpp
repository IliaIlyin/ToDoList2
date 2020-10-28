//
// Created by Ilya on 9/15/2020.
//

#include "ShowAllByPriorityCommandBuilder.h"
std::shared_ptr<Command> ShowAllByPriorityCommandBuilder::buildCommand(std::shared_ptr<ClientInterface> service) {
  return std::make_shared<ShowAllByPriorityCommand>(service);
}