%{
#include <stdio.h>
int cc = 0, wc = 0, lc = 0, sp = 0;
%}
%%
[^ \t\n]+ {wc++; cc += yyleng;}
[\n] {lc++;}
[\t] {sp += 5;}
[ ] {sp++; cc++;}
. {cc++;}
%%
int main(int argc, char * argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("Char = %d\n",cc);
	printf("Space = %d\n",sp);
	printf("Word = %d\n",wc);
	printf("line = %d\n",lc);
	return 0;
}
