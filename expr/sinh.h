#ifndef SINH_H 
#define SINH_H 

#include "function.h"
#include "mul.h"
#include "cosh.h"

class SinhExpression : public FunctionExpression
{
  public:
    SinhExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // SINH_H 
