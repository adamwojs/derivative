#ifndef CTGH_H 
#define CTGH_H 

#include "function.h"
#include "neg.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "sinh.h"

class CtghExpression : public FunctionExpression
{
  public:
    CtghExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // CTGH_H 
