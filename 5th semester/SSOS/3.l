%{
#include <stdio.h>
int count = 0;
%}
ID [a-zA-Z][a-zA-Z0-9]*
%s DEFN
%%
[ \t\n] ;
"int "|"char "|"double "|"float " {BEGIN DEFN;}
<DEFN>{ID}"," {count++; printf("%s\n",yytext);}
<DEFN>{ID}";" {count++; printf("%s\n",yytext); BEGIN 0;}
<DEFN>{ID}"=" {count++; printf("%s\n",yytext);}
.|\n ;
%%
int main(int argc, char * argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("No of identifiers = %d\n",count);
	return 0;
}
