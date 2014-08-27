#include "mul.h"

MulExpression::MulExpression(Expression* arg0, Expression* arg1) 
{
  this->args.push_back(arg0);
  this->args.push_back(arg1);
}

Expression* MulExpression::derivative()
{
  // (f * g)' = f' * g + f * g'
  return new AddExpression(
      new MulExpression( 
	this->args[0]->derivative(), this->args[1]
      ),
      new MulExpression(
	this->args[0], this->args[1]->derivative()
      )
  );
}

std::string MulExpression::toString()
{
    return '(' + this->args[0]->toString() + ") * (" + this->args[1]->toString() + ')';
}

bool MulExpression::is_complex()
{
  return false;
}
