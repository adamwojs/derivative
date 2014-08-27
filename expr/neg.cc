#include "neg.h"

NegExpression::NegExpression(Expression* arg) 
{
  this->args.push_back(arg);
}

Expression* NegExpression::derivative()
{
  return new MulExpression(new ConstExpression(-1), this->args[0]->derivative());
}

std::string NegExpression::toString()
{
  return "-" + this->args[0]->toString();
}

bool NegExpression::is_complex()
{
  return false;
}
