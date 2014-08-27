#ifndef NEG_H 
#define NEG_H 

#include "../expression.h"
#include "mul.h"
#include "const.h"

class NegExpression : public Expression
{
  public:
    NegExpression(Expression* arg);  

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
}; 

#endif // NEG_H 
