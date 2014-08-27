#ifndef VAR_H 
#define VAR_H 

#include "../expression.h"
#include "const.h"

class VarExpression : public Expression
{
  public:
    VarExpression();

    virtual std::string toString();
    virtual Expression* derivative();
    virtual bool is_complex();
}; 

#endif // VAR_H 
