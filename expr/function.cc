#include "function.h"

std::string FunctionExpression::toString()
{
    return this->name + '(' + this->args[0]->toString() + ')';
}

bool FunctionExpression::is_complex()
{
  Expression* arg = this->args[0];
  
  if(typeid(*arg) == typeid(VarExpression))
    return false;
  
  if(typeid(*arg) == typeid(ConstExpression))
    return false;
  
  return true;
}
