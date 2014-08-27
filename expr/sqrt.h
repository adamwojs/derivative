#ifndef SQRT_H
#define SQRT_H

#include "function.h"
#include "mul.h"
#include "div.h"

class SqrtExpression : public FunctionExpression
{
	public:
		SqrtExpression(Expression* arg);
		
		virtual Expression* derivative();	
};

#endif // SQRT_H
