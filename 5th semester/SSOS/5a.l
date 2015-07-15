%{
#include "y.tab.h"
extern int yylval;
%}
%%
[0-9]+ {yylval= atoi(yytext);
 	 return NUM;}
[a-zA-Z][a-zA-Z0-9]* return ID;
. {return yytext[0];}
\n return 0;
%%
