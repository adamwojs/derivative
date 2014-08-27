#include "pow.h"

PowExpression::PowExpression(Expression* arg0, Expression* arg1) 
{
  this->args.push_back(arg0);
  this->args.push_back(arg1);
}

Expression* PowExpression::derivative()
{ 
  Expression* dx = NULL;
  Expression* b  = this->args[0];  // Podstawa potęgi
  Expression* e  = this->args[1];  // Wykładnik potęgi
  
  // Czy podstawa potęgi jest stała  ?
  if(typeid(*b) == typeid(ConstExpression) || typeid(*b) == typeid(EConstExpression)) {
  	// Czy wykładnik jest stały ?
  	if(typeid(*e) == typeid(ConstExpression) || typeid(*e) == typeid(EConstExpression)) {
  		// Stała: a ^ b  
	  	return new ConstExpression(0); 
  	}
  	else
  	{  	
  		if(typeid(*b) == typeid(EConstExpression)) {
	  		// e^x 	
	  		dx = new PowExpression(new EConstExpression(), e);
	  		// Wykładnik jest f. złożoną  ?
	  		if(e->is_complex()) {
	  			return new MulExpression(dx, e->derivative());
	  		}
	  		return dx;
  		}
  		else {
	  		// Funckcja wykładnicza: (a^x)' = a^x * ln(a)			
	  		dx = new MulExpression(
	  			new PowExpression(b, this->args[0]), new LnExpression(b)
	  		);
	  		// Wykładnik jest f. złożoną  ?
			if(e->is_complex()) {
				return new MulExpression(dx, e->derivative());			
			}			
			return dx;
  		}		
  	}		  	
  }
  else {
	if(typeid(*e) == typeid(ConstExpression) || typeid(*e) == typeid(EConstExpression)) {
		// Funkcja potęgowa: (x^a)' = a * x^(a - 1)	
		dx = new MulExpression(
			e, new PowExpression(b, new SubExpression(e, new ConstExpression(1)))
		);

		// Podstawa jest f. złożoną ?
		if(b->is_complex()) {
			return new MulExpression(dx, b->derivative());
		}

		return dx;
	}		
  }
    
  // Podstawa i wykladnik sa f. złożoną
  // Wzór wyprowadziła Ania :-)
  return new ConstExpression(-999999.9);
}

std::string PowExpression::toString()
{
  return '(' + this->args[0]->toString() + ") ^ (" + this->args[1]->toString() + ')';  
}

