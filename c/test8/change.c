#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    FILE *fp;
    char a[40];
    int i=0;
    fp=fopen("test.txt","w");
    gets(a);
    a[0]=toupper(a[0]);
    while (*(a+i)!='\0')
    {
        if(islower(*(a+i))&&*(a+i-1)==' '){
            *(a+i)=toupper(*(a+i));
        }
        i++;
    }
    puts(a);
    fputs(a,fp);
    fclose(fp);
    system("pause");
    return 0;
}