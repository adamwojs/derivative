#include "cos.h"

CosExpression::CosExpression(Expression* arg) 
{
  this->name = "cos";

  this->args.push_back(arg);
}

Expression* CosExpression::derivative()
{
  if (!this->is_complex()) {
    return new NegExpression(new SinExpression(this->args[0]));
  }
    
  return new MulExpression(
    new NegExpression(new SinExpression(this->args[0])), this->args[0]->derivative()
  );  
}

