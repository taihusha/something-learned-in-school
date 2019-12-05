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
{int}        {yylval.type_int=atoi(yytext);printf("(%d,%d)\n",INT,yylval.type_int); return INT;}
{float}      {yylval.type_float=atof(yytext);printf("(%d,%fl)\n",FLOAT,yylval.type_float); return FLOAT;}
{char}		 {yylval.type_char=yytext[1];printf("(%d,%c)\n",CHAR,yylval.type_char);return CHAR;}
{linecom}	 {printf("(%d,zhushi)\n",LINECOM);}
"int"        {strcpy(yylval.type_id,  yytext);printf("(%d,int)\n",TYPE_I,yylval.type_id);return TYPE_I;}
"float"      {strcpy(yylval.type_id,  yytext);printf("(%d,float)\n",TYPE_F,yylval.type_id);return TYPE_F;}
"char"		 {strcpy(yylval.type_id,  yytext);printf("(%d,char)\n",TYPE_I,yylval.type_id);return TYPE_C;}


"return"     {printf("(%d,return)\n",RETURN);return RETURN;}
"if"         {printf("(%d,if)\n",IF);return IF;}
"else"       {printf("(%d,else)\n",ELSE);return ELSE;}
"while"      {printf("(%d,while)\n",WHILE);return WHILE;}
"break"		 {printf("(%d,break)\n",BREAK);return BREAK;}
"continue"	 {printf("(%d,continue)\n",CONTINUE);return CONTINUE;}

{id}        {strcpy(yylval.type_id,  yytext); printf("(%d,%s)\n",ID,yylval.type_id); return ID;}
";"			{printf("(%d, ;)\n",SEMI);return SEMI;}
","			{printf("(%d, ,)\n",COMMA);return COMMA;}
"#"			{printf("(%d,')\n",QM);return QM;}
">"|"<"|">="|"<="|"=="|"!=" {strcpy(yylval.type_id, yytext);printf("(%d,%s)\n",RELOP,yylval.type_id);return RELOP;}
"="			{printf("(%d,=)\n",ASSIGNOP);return ASSIGNOP;}
"+"			{printf("(%d,+)\n",PLUS);return PLUS;}
"++"		{printf("(%d,++)\n",DPLUS);return DPLUS;}
"-"			{printf("(%d,-)\n",MINUS);return MINUS;}
"--"		{printf("(%d,--)\n",DMINUS);return DMINUS;}
"*"			{printf("(%d,*)\n",STAR);return STAR;}
"/"			{printf("(%d,/)\n",DIV);return DIV;}
"&&"        {printf("(%d,&&)\n",AND);return AND;}
"||"        {printf("(%d,||)\n",OR);return OR;}
"!"			{printf("(%d,!)\n",NOT);return NOT;}
"("			{printf("(%d,()\n",LP);return LP;}
")"			{printf("(%d,))\n",RP);return RP;}
"["		    {printf("(%d,[)\n",LB);return LB;}
"]"		    {printf("(%d,])\n",RB);return RB;}	
"{"			{printf("(%d,{)\n",LC);return LC;}
"}"			{printf("(%d,})\n",RC);return RC;}
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
