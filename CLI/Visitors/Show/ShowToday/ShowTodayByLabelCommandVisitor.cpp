//
// Created by Ilya on 9/21/2020.
//

#include "ShowTodayByLabelCommandVisitor.h"
void ShowTodayByLabelCommandVisitor::visitShowTodayByLabelCommand(ShowTodayByLabelCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowTodayByLabelCommandVisitor::ShowTodayByLabelCommandVisitor(const std::shared_ptr<Context> &context) : context_(
    context) {}
