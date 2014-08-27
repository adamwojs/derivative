%{
  #include <iostream>
  #include "expressions.h"

  #define YYERROR_VERBOSE

  int yyerror(char* s) {
    std::cerr << s << std::endl;
    return 0;
  }
  
  int yylex(void); 
%}

%union {
  double val;
  Expression* expr;
}

%token <val>NUMBER
%token SQRT
%token SIN 
%token COS
%token TG 
%token CTG 
%token ARCSIN 
%token ARCCOS 
%token ARCTG 
%token ARCCTG 
%token LN 
%token LOG 
%token SINH 
%token COSH 
%token TGH 
%token CTGH

%type <expr> EXPR
%type <expr> FUNCTION

%left 	'+' '-'
%left 	'*' '/'
%left 	NEG
%right 	'^'

%%

LIST_OF_EXPRESSIONS:
  EXPR '\'' 
  { 
  	Expression* dx = $1->derivative();
    std::cout << "\t= " << dx->toString() << std::endl; 
    delete dx;
  } 
  LIST_OF_EXPRESSIONS
    |
  	/* Epsilon */
    ;

EXPR:    
  'e'
  { $$ = new EConstExpression(); }
  	|     
  'x' 
  { $$ = new VarExpression(); }
    |
  NUMBER
  { $$ = new ConstExpression($1); }
    |
  EXPR '+' EXPR 
  { $$ = new AddExpression($1, $3); } 
    |
  EXPR '-' EXPR 
  { $$ = new SubExpression($1, $3); }
    |
  EXPR '*' EXPR 
  { $$ = new MulExpression($1, $3); }
    |
  NUMBER FUNCTION
  { $$ = new MulExpression(new ConstExpression($1), $2); }
    |              
  NUMBER 'e'
  { $$ = new MulExpression(new ConstExpression($1), new EConstExpression()); }  
  	|
  NUMBER 'x'	
  { $$ = new MulExpression(new ConstExpression($1), new VarExpression()); }  
  	|    
  EXPR '/' EXPR
  { $$ = new DivExpression($1, $3); }
    |
  EXPR '^' EXPR 
  { $$ = new PowExpression($1, $3); }
    |
  '-' EXPR %prec NEG 
  { $$ = new NegExpression($2); }
  	|
  '(' EXPR ')'
  { $$ = $2; }	
    |
  FUNCTION
  { $$ = $1; }
    ;

FUNCTION:
  SQRT   '(' EXPR ')'
  { $$ = new SqrtExpression($3); }
  	|
  SIN 	 '(' EXPR ')' 	
  { $$ = new SinExpression($3); } 	
    | 
  COS 	 '(' EXPR ')' 	
  { $$ = new CosExpression($3); } 	
  	|
  TG  	 '(' EXPR ')' 	
  { $$ = new TgExpression($3); }  	
  	|
  CTG 	 '(' EXPR ')' 	
  { $$ = new CtgExpression($3); } 	
  	|
  ARCSIN '(' EXPR ')' 	
  { $$ = new ArcsinExpression($3); } 	
  | 
  ARCCOS '(' EXPR ')' 	
  { $$ = new ArccosExpression($3); } 	
  |
  ARCTG  '(' EXPR ')' 	
  { $$ = new ArctgExpression($3); }	
  |
  ARCCTG '(' EXPR ')' 	 
  { $$ = new ArcctgExpression($3); }	
  |  
  LN 	 '(' EXPR ')' 	 
  { $$ = new LnExpression($3); } 	
  |
  LOG 	 '(' EXPR ',' EXPR ')' 	 
  { $$ = new LogExpression($3, $5); } 	
  |
  SINH 	 '(' EXPR ')' 	 
  { $$ = new SinhExpression($3); } 	
  |
  COSH 	 '(' EXPR ')' 	 
  { $$ = new CoshExpression($3); } 	
  |
  TGH 	 '(' EXPR ')' 	 
  { $$ = new TghExpression($3); } 	
  |
  CTGH 	 '(' EXPR ')' 	 
  { $$ = new CtghExpression($3); } 	
  ;
	
%%

int main(int argc, char* argv[])
{
  std::cout << "Kalkulator pochonych | Adam Wójs" << std::endl << std::endl;
  yyparse();
  return 0;
} 
