#include "div.h"

DivExpression::DivExpression(Expression* arg0, Expression* arg1) 
{
  this->args.push_back(arg0);
  this->args.push_back(arg1);
}

Expression* DivExpression::derivative()
{
  // (f / g)' = (f' * g - f * g') / (g ^ 2)  
  SubExpression* dividend = new SubExpression(
    new MulExpression(this->args[0]->derivative(), this->args[1]),
    new MulExpression(this->args[0], this->args[1]->derivative())
  );
  PowExpression* divisor = new PowExpression(
    this->args[1], new ConstExpression(2)
  );  
  
  return new DivExpression(dividend, divisor);
}

std::string DivExpression::toString()
{
  return '(' + this->args[0]->toString() + ") / (" + this->args[1]->toString() + ')';
}

bool DivExpression::is_complex()
{
  return false;
}

