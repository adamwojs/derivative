#include "var.h"

VarExpression::VarExpression() {}

Expression* VarExpression::derivative()
{
  return new ConstExpression(1);
}

std::string VarExpression::toString()
{
  return "x";
}

bool VarExpression::is_complex()
{
  return false;
}
