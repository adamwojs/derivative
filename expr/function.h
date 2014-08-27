#ifndef FUNCTION_H
#define FUNCTION_H

#include <typeinfo>
#include "../expression.h"
#include "const.h"
#include "var.h"

class FunctionExpression : public Expression
{
    public:

        virtual std::string toString();	
	bool is_complex();
    protected:
        std::string name;
};

#endif // FUNCTION_H
