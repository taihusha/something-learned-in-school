#include "def.h"


// semantic.c
void semantic_error(int line, char *msg1, char *msg2);
void prn_symbol();
int searchSymbolTable(char *name);
int fillSymbolTable(char *name, char *alias, int level, int type, char flag, int offset);
int fill_Temp(char *name, int level, int type, char flag, int offset);
int match_param(int i, struct ASTNode *T);
void Exp(struct ASTNode *T);
void semantic_Analysis(struct ASTNode *T);
void semantic_Analysis0(struct ASTNode *T);

// code.c
char *strcat0(char *s1, char *s2);
char *newAlias();
char *newLabel();
char *newTemp();
struct codenode *genIR(int op, struct opn opn1, struct opn opn2, struct opn result);
struct codenode *genLabel(char *label);
struct codenode *genGoto(char *label);
struct codenode *merge(int num, ...);
void prnIR(struct codenode *head);

// exp.c
void boolExp(struct ASTNode *T);

// semantic_case.c
void ext_var_list(struct ASTNode *T);
