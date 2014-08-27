#include "add.h"

AddExpression::AddExpression(Expression* arg0, Expression* arg1) 
{
  this->args.push_back(arg0);
  this->args.push_back(arg1);
}

Expression* AddExpression::derivative()
{
  return new AddExpression(
      this->args[0]->derivative(),
      this->args[1]->derivative()
  );
}

std::string AddExpression::toString()
{
  return '(' + this->args[0]->toString() + ") + (" + this->args[1]->toString() + ')';
}

bool AddExpression::is_complex()
{
  return false;
}
