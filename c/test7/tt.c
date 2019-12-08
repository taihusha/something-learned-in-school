#include<stdio.h>
#include<stdlib.h>
char u[]="UVWXYZ";
char v[]="xyz";
struct T{
	int x;
	char c;
	char *t;
}a[]={{11,'A',u},{100,'B',v}},*p=a;

int main()
{
/* 	printf("(++p)->x:%d",(++p)->x);
	printf("\n"); */
/* 	p++;
	printf("p++,p->c:%c",p->c);
	printf("\n"); */
/* 	*p++->t;
	printf("*p++->t,*p->t:%c",*p->t);
	printf("\n"); */
/*  	printf("*(++p)->t:%c",*(++p)->t);
	printf("\n"); */
/* 	printf("*++p->t:%c",*++p->t);
	printf("\n"); */
	printf("++*p->t:%c",++*p->t);
	printf("\n");
	system("pause");
    return 0;
}