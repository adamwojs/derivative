#ifndef DIV_H 
#define DIV_H 

#include "../expression.h"
#include "pow.h"
#include "sub.h"
#include "mul.h"

class DivExpression : public Expression
{
  public:
    DivExpression(Expression* arg0, Expression* arg1);  

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
}; 

#endif // DIV_H 
