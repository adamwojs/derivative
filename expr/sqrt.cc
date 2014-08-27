#include "sqrt.h"

SqrtExpression::SqrtExpression(Expression* arg)
{
	this->name = "sqrt";
	this->args.push_back(arg);	
}

Expression* SqrtExpression::derivative()
{
	// Sqrt(x)' = 1 / (2 * sqrt(x))
	Expression* dx = new DivExpression(
		new ConstExpression(1), new MulExpression(new ConstExpression(2), new SqrtExpression(this->args[0]))
	);
	
	if(this->is_complex()) {
		return new MulExpression(dx, this->args[0]->derivative());
	}
	
	return dx;	
}
