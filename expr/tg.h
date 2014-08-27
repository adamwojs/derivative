#ifndef TG_H 
#define TG_H 

#include "function.h"
#include "const.h"
#include "mul.h"
#include "div.h"
#include "pow.h"
#include "cos.h"

class TgExpression : public FunctionExpression
{
  public:
    TgExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // TG_H 
