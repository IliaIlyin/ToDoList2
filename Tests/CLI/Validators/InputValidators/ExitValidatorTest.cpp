//
// Created by ilya on 19.10.20.
//

#include <gtest/gtest.h>
#include "Validators/InputValidators/ExitValidator.h"
class ExitValidatorTest : public testing::Test {

};
TEST_F(ExitValidatorTest, shouldValidateInput) {
  ExitValidator validator;
  std::string f = "FDSFDS";
  std::string f2 = "2000/11/11";
  std::string f3 = "";
  std::string f4 = "cancel command";
  ASSERT_EQ(validator.validate(f), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f3), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f4), GeneralInputValidator::InputToken::CORRECT);

}