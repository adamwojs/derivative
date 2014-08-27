#include "sin.h"

SinExpression::SinExpression(Expression* arg) 
{
  this->name = "sin";

  this->args.push_back(arg);
}

Expression* SinExpression::derivative()
{
  if (!this->is_complex()) {
    return new CosExpression(this->args[0]);
  }
    
  return new MulExpression(
    new CosExpression(this->args[0]), this->args[0]->derivative()
  );  
}

