#include <cstdio>
#include "const.h"

ConstExpression::ConstExpression(double v) 
{
  this->v = v;
}

Expression* ConstExpression::derivative()
{
  // (const)' = 0
  return new ConstExpression(0);
}

std::string ConstExpression::toString()
{
  // Konwersacja double => string
  char s[10];
  sprintf(s, "%f", this->v);  
  return s;
}

bool ConstExpression::is_complex()
{
  return false;
}