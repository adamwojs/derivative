#ifndef COSH_H 
#define COSH_H 

#include "function.h"
#include "mul.h"
#include "sinh.h"

class CoshExpression : public FunctionExpression
{
  public:
    CoshExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // COSH_H 
