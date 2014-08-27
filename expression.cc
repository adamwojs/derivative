#include "expression.h"

Expression::~Expression()
{
    // Zwalniamy pamięć zajmowaną przez argumenty
    for (std::vector<Expression*>::iterator i = this->args.begin();
         i != this->args.end(); ++i)
    {
        delete *i;
    }
}
