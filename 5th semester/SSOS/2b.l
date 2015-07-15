%{
#include <stdio.h>
int flag = 0;
%}
%%
^(" and "|" or "|" because "|" but "|" with ") {flag = 0;}
(" and "|" or "|" because "|" but "|" with ") {flag = 1;}
\n {return 0;} 
%%
int main(void)
{
	printf("Enter stmt\n");
	yylex();
	if(flag == 0)
		printf("Simple stmt\n");
	else
		printf("Compound stmt\n");
	return 0;
}
