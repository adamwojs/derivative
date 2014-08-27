#ifndef TGH_H 
#define TGH_H 

#include "function.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "cosh.h"

class TghExpression : public FunctionExpression
{
  public:
    TghExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // TGH_H 
