#include<stdio.h>
#include<stdlib.h>
char *strcpy(char *,char *);
int main()
{
    char a[30],b[60]="there is a boat on the lake.";
    strcpy(a,b);
    printf("%s\n",a);
    system("pause");
    return 0;
}
char *strcpy(char *s,char *t)
{
    while(*s++=*t++)
             ;
    return (s);
}
