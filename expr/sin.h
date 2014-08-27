#ifndef SIN_H 
#define SIN_H 

#include "function.h"
#include "mul.h"
#include "cos.h"

class SinExpression : public FunctionExpression
{
  public:
    SinExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // SIN_H 
