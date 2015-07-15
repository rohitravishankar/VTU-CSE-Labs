%{
#include <stdio.h>
#include <stdlib.h>
%}
%token A B
%%
S: A S B
   |;
%%
yyerror()
{
	printf("Invalid string\n");
	exit(0);
}

int main(void)
{
	printf("Enter string\n");
	yyparse();
	printf("Valid string\n");
	return 0;
}
