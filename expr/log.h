#ifndef LOG_H 
#define LOG_H 

#include "function.h"
#include "mul.h"
#include "div.h"
#include "ln.h"

class LogExpression : public FunctionExpression
{
  public:
    LogExpression(Expression* arg0, Expression* arg1);  

    virtual Expression* derivative();
}; 

#endif // LOG_H 
