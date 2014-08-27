#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <vector>
#include <cassert>

/**
 * Bazowa klasa reprezentująca wyrażenie matematyczne
 *
 * @author Adam Wójs
 */
class Expression
{
    public:
        virtual ~Expression();

        // Konwerteruje wyrażenie do napisu
        virtual std::string toString() = 0;

        // Oblicza pochodna wyrazenia
        virtual Expression* derivative() = 0;		

        // Czy wyrażenie jest złożone ?
        virtual bool is_complex() = 0;
	
    protected:
    	// Argmenty wyrażenia
        std::vector<Expression*> args;
};

#endif // EXPRESSION_H
