#include "ln.h"

LnExpression::LnExpression(Expression* arg) 
{
  this->name = "ln";

  this->args.push_back(arg);
}

Expression* LnExpression::derivative()
{
  // (ln(x)' = 1/x
  Expression* dx = new DivExpression(
    new ConstExpression(1), this->args[0]
  );
  
  if(this->is_complex()) {
    return new MulExpression(dx, this->args[0]->derivative());
  }
    
  return dx;  
}

