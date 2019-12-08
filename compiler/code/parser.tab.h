
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     ID = 259,
     RELOP = 260,
     TYPE_I = 261,
     TYPE_F = 262,
     TYPE_C = 263,
     FLOAT = 264,
     CHAR = 265,
     DPLUS = 266,
     DMINUS = 267,
     LP = 268,
     RP = 269,
     LC = 270,
     RC = 271,
     SEMI = 272,
     COMMA = 273,
     LB = 274,
     RB = 275,
     QM = 276,
     LINECOM = 277,
     BLOCKCOM = 278,
     ARRAY_DEF = 279,
     ARRAY_EXP = 280,
     PLUS = 281,
     MINUS = 282,
     STAR = 283,
     DIV = 284,
     ASSIGNOP = 285,
     AND = 286,
     OR = 287,
     NOT = 288,
     IF = 289,
     ELSE = 290,
     WHILE = 291,
     RETURN = 292,
     BREAK = 293,
     CONTINUE = 294,
     FOR = 295,
     SWITCH = 296,
     CASE = 297,
     COLON = 298,
     DEFAULT = 299,
     EXT_DEF_LIST = 300,
     EXT_VAR_DEF = 301,
     FUNC_DEF = 302,
     FUNC_DEC = 303,
     EXT_DEC_LIST = 304,
     PARAM_LIST = 305,
     PARAM_DEC = 306,
     VAR_DEF = 307,
     DEC_LIST = 308,
     DEF_LIST = 309,
     COMP_STM = 310,
     STM_LIST = 311,
     FOR_DEC = 312,
     EXP_STMT = 313,
     IF_THEN = 314,
     IF_THEN_ELSE = 315,
     FUNC_CALL = 316,
     ARGS = 317,
     FUNCTION = 318,
     PARAM = 319,
     ARG = 320,
     CALL = 321,
     LABEL = 322,
     GOTO = 323,
     JLT = 324,
     JLE = 325,
     JGT = 326,
     JGE = 327,
     EQ = 328,
     NEQ = 329,
     UMINUS = 330,
     LOWER_THEN_ELSE = 331
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "parser.y"

	int    type_int;
	float  type_float;
        char   type_char;
	char   type_id[32];
	struct ASTNode *ptr;



/* Line 1676 of yacc.c  */
#line 138 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

