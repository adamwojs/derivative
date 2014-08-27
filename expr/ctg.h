#ifndef CTG_H 
#define CTG_H 

#include "function.h"
#include "const.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "neg.h"
#include "sin.h"

class CtgExpression : public FunctionExpression
{
  public:
    CtgExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // CTG_H 
