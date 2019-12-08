%x COMMENT
%{
#include "parser.tab.h"
#include "string.h"
#include "def.h"
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
typedef union {
	int type_int;
	int type_float;
	char type_char;
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
%option yylineno

id   [A-Za-z][A-Za-z0-9]*  
int    [0-9]+
float  ([0-9]*\.[0-9]+)|([0-9]+\.)
char   '.'
linecom    	"//".*

%%
{int}        {yylval.type_int=atoi(yytext);return INT;}
{float}      {yylval.type_float=atof(yytext);return FLOAT;}
{char}		 {yylval.type_char=yytext[1];return CHAR;}
{linecom}	 {}
"int"        {strcpy(yylval.type_id,  yytext);return TYPE_I;}
"float"      {strcpy(yylval.type_id,  yytext);return TYPE_F;}
"char"		 {strcpy(yylval.type_id,  yytext);return TYPE_C;}


"return"     {return RETURN;}
"if"         {return IF;}
"else"       {return ELSE;}
"while"      {return WHILE;}
"for"        {return FOR;}
"break"		 {return BREAK;}
"continue"	 {return CONTINUE;}

{id}        {strcpy(yylval.type_id,  yytext); return ID;}
";"			{return SEMI;}
","			{return COMMA;}
"#"			{return QM;}
">"|"<"|">="|"<="|"=="|"!=" {strcpy(yylval.type_id, yytext);return RELOP;}
"="			{return ASSIGNOP;}
"+"			{return PLUS;}
"++"		{return DPLUS;}
"-"			{return MINUS;}
"--"		{return DMINUS;}
"*"			{return STAR;}
"/"			{return DIV;}
"&&"        {return AND;}
"||"        {return OR;}
"!"			{return NOT;}
"("			{return LP;}
")"			{return RP;}
"["		    {return LB;}
"]"		    {return RB;}	
"{"			{return LC;}
"}"			{return RC;}
[\n]           {yycolumn=1;}   
[ \t\r]          {}
.			{printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
<<EOF>> { return 0;}
"/*" {
	char c;
	while(1)
	{
		while((c=input())!='*'&&c!=EOF);
		if(c=='*')
		{
			while((c=input())=='*');
			if(c=='/')
				break;
		}
		if(c==EOF)
		{
			break;
		}
	}
}
%%

// 和bison联用时，不需要这部分


int yywrap()
{
return 1;
}
