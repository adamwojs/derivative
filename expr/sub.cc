#include "sub.h"

SubExpression::SubExpression(Expression* arg0, Expression* arg1) 
{
  this->args.push_back(arg0);
  this->args.push_back(arg1);
}

Expression* SubExpression::derivative()
{
  return new SubExpression(
      this->args[0]->derivative(),
      this->args[1]->derivative()
  );
}

std::string SubExpression::toString()
{
   return '(' + this->args[0]->toString() + ") - (" + this->args[1]->toString() + ')';
}

bool SubExpression::is_complex()
{
  return false;
}
