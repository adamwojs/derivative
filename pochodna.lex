%{
  #include <cstdlib>

  #include "expression.h"
  #include "pochodna.tab.h"
%}

%option noyywrap

space	[ \t\n]+
number 	[0-9][1-9]*(\.[0-9][0-9]+)?

%%

{space} 	{ /* Pomijamy białe znaki */ }
{number}	{
  yylval.val = atof(yytext); 
  return NUMBER; 
}
sqrt		{ return SQRT; }
sin			{ return SIN; }
cos			{ return COS; }
tg			{ return TG;  }
ctg			{ return CTG; }
arcsin		{ return ARCSIN; }
arccos		{ return ARCCOS; }
arctg		{ return ARCTG;  }
arcctg		{ return ARCCTG; }
ln			{ return LN; }
log			{ return LOG; }
sinh		{ return SINH; }
cosh		{ return COSH; }
tgh			{ return TGH;  }
ctgh		{ return CTGH; }
.			{ return yytext[0]; }

%%
