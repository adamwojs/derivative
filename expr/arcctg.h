#ifndef ARCCTG_H 
#define ARCCTG_H 

#include "function.h"
#include "add.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "neg.h"

class ArcctgExpression : public FunctionExpression
{
  public:
    ArcctgExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // ARCCTG_H 
