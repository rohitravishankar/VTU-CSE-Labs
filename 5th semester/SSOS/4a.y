%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUM,ID
%left '+''-'
%left '*''/'
%%
exp: exp'+'exp
     |exp'-'exp
     |exp'*'exp
     |exp'/'exp
     |'('exp')'
     |NUM
     |ID
     ;
%%
yyerror()
{
	printf("Invalid exp");
	exit(0);
}

int main(void)
{
	printf("Enter exp\n");
	yyparse();
	printf("Valid exp\n");
	return 0;
}
