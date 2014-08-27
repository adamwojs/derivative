#ifndef POW_H 
#define POW_H 

#include <typeinfo>
#include "function.h"
#include "econst.h"
#include "sub.h"
#include "mul.h"
#include "ln.h"

class PowExpression : public FunctionExpression 
{
  public:
    PowExpression(Expression* arg0, Expression* arg1);  

    virtual std::string toString();
    virtual Expression* derivative();
}; 

#endif // POW_H 
