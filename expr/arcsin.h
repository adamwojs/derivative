#ifndef ARCSIN_H 
#define ARCSIN_H 

#include "function.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "sqrt.h"

class ArcsinExpression : public FunctionExpression
{
  public:
    ArcsinExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // ARCSIN_H 
