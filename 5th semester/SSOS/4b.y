%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUM ID
%%
var: ID
    |var ID
    |var NUM;
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
