#ifndef LN_H 
#define LN_H 

#include "function.h"
#include "div.h"

class LnExpression : public FunctionExpression
{
  public:
    LnExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // LN_H 
