//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Builders/Show/ShowDueDate/ShowDueDateByLabelCommandBuilder.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "InputStateMachineInterface.h"
#include "CLI/Mocks/InputStateMachine.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class ShowDueDateByLabelCommandBuilderTest : public testing::Test {

};

TEST_F(ShowDueDateByLabelCommandBuilderTest, shouldCreateShowDueDateByLabelommand) {
  auto mock = std::make_unique<InputStateMachineMock>();
  InputContext context;
  context.setName("ELON");
  context.setDate(boost::gregorian::date{2000, 11, 11});
  context.setLabel("label");
  context.setId(TaskID(1));
  context.setPriority(Task::Priority::FIRST);
  auto service = std::make_shared<CoreAPIMock>();
  auto validator = std::make_shared<TaskNameValidator>();
  EXPECT_CALL(mock.operator*(), run()).WillOnce(Return(GeneralInputValidator::InputToken::SUCCESS));
  EXPECT_CALL(mock.operator*(), GetContext()).WillOnce(Return(context));
  ShowDueDateByLabelCommandBuilder builder(std::move(mock));
  auto res = builder.buildCommand(service);
  ASSERT_NE(res.get(), nullptr);
}
TEST_F(ShowDueDateByLabelCommandBuilderTest, shouldCreateCancelCommand) {
  auto mock = std::make_unique<InputStateMachineMock>();
  InputContext context;
  context.setName("ELON");
  context.setDate(boost::gregorian::date{2000, 11, 11});
  context.setLabel("label");
  context.setId(TaskID(1));
  context.setPriority(Task::Priority::FIRST);
  auto service = std::make_shared<CoreAPIMock>();
  auto validator = std::make_shared<TaskNameValidator>();
  EXPECT_CALL(mock.operator*(), run()).WillOnce(Return(GeneralInputValidator::InputToken::CANCEL_COMMAND));
//  EXPECT_CALL(mock.operator*(), GetContext()).WillOnce(Return(context));
  ShowDueDateByLabelCommandBuilder builder(std::move(mock));
  auto res = builder.buildCommand(service);
  ASSERT_NE(res.get(), nullptr);
}
