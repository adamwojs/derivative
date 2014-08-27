#ifndef ADD_H 
#define ADD_H 

#include "../expression.h"

class AddExpression : public Expression
{
  public:
    AddExpression(Expression* arg0, Expression* arg1);  

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
}; 

#endif // ADD_H 
