%{
#include <stdio.h>
#include <stdlib.h>
int count = 0;
%}
%token A B
%%
S: X B;
X: X A {count++;}
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
	if(count >= 10)
		printf("Valid string\n");
	else
		yyerror();
	return 0;
}
