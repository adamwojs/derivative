#ifndef MUL_H 
#define MUL_H 

#include "../expression.h"
#include "add.h"

class MulExpression : public Expression
{
  public:
    MulExpression(Expression* arg0, Expression* arg1);  

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
}; 

#endif // MUL_H 
