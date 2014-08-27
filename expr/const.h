#ifndef CONST_H 
#define CONST_H 

#include "../expression.h"

class ConstExpression : public Expression
{
  public:
    ConstExpression(double v);  

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
  protected:
    double v;
}; 

#endif // CONST_H 
