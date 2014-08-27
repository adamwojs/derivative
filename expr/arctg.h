#ifndef ARCTG_H 
#define ARCTG_H 

#include "function.h"
#include "add.h"
#include "mul.h"
#include "div.h"
#include "pow.h"

class ArctgExpression : public FunctionExpression
{
  public:
    ArctgExpression(Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // ARCTG_H 
