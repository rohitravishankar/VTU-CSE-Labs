%{
 #include <stdio.h>
 int comment = 0;
%}
%s COMM
%%
"//".* {comment++;}
"/*".*"*/" { comment++;}
"/*" {BEGIN COMM; comment++;}
<COMM>. ;
<COMM>\n;
<COMM>"*/" {BEGIN 0;}
%%
int main(int argc, char * argv[])
{
	yyin = fopen(argv[1],"r");
	yyout = fopen(argv[2],"w");
	yylex();
	printf("Comments = %d\n",comment);
	return 0;
}
