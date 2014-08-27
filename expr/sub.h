#ifndef SUB_H 
#define SUB_H 

#include "../expression.h"

class SubExpression : public Expression
{
  public:
    SubExpression(Expression* arg0, Expression* arg1);  

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
}; 

#endif // SUB_H 
