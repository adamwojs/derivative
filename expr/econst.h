#ifndef E_H
#define E_H

#include "const.h"

class EConstExpression : public ConstExpression
{
  public: 
	  EConstExpression();
  
	  virtual std::string toString();
};

#endif // E_H
