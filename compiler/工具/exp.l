%{
#include "exp.tab.h"
#include "stdio.h"
#include "string.h"
typedef union {
	int type_int;
	char type_id[32];
   } YYLVAL;
#define YYSTYPE YYLVAL
%}

%%
0|[1-9][0-9]*              { yylval.type_int=atoi(yytext);	return INTEGER; }
[a-zA-Z][a-zA-Z0-9]*       { strcpy(yylval.type_id,yytext);	return ID; }
[+*()]          {return yytext[0];}
[\n]            {return yytext[0];}
.             {/*do nothing*/return yytext[0];}
%%

int yywrap()
{
return 1;
}

