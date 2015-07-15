%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUM ID
%left '+''-'
%left '*''/'
%%
stmt: ID'='exp
     |exp {printf("%d\n",$1);}
     ;
exp: exp'+'exp { $$ = $1+$3;} 
     |exp'-'exp { $$ = $1-$3;}
     |exp'*'exp { $$ = $1*$3;}
     |exp'/'exp { $$ = $1/$3;}
     |'('exp')' {$$ = $2;}
     |NUM  { $$ = $1;}
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
/*	if(!yyparse() && value==1)
	{
	printf("Valid exp\n");
	printf("Result : %d",ans);	
	}	
	else if(valid==0)
	{
	yyerror();
	}*/
	yyparse();
	printf("VALID\n");
return 0;	 
}
