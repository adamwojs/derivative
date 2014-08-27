#ifndef ARCCOS_H 
#define ARCCOS_H 

#include "function.h"
#include "neg.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "sqrt.h"

class ArccosExpression : public FunctionExpression
{
  public:
    ArccosExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // ARCCOS_H 
