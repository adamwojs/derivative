#ifndef COS_H 
#define COS_H 

#include "function.h"
#include "neg.h"
#include "sin.h"

class CosExpression : public FunctionExpression
{
  public:
    CosExpression(Expression* arg);

    virtual Expression* derivative();
}; 

#endif // COS_H 
