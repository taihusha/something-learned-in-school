/* 利用大小为n的指针数组指向用gets函数输入的n行，每行不超过80个字符。
编写一个函数，它将每一行中连续的多个空格字符压缩为一个空格字符。
在调用函数中输出压缩空格后的各行，空行不予输出 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 80
void space(char *p[],int n);
int main()
{
    int num;
    printf("input the num of lines:\n");
    scanf("%d",&num);
    num++;
    char s[num][N],*p[num];
    for(int i=0;i<num;i++){
        gets(s[i]);
        p[i]=s[i];
    }
    space(p,num);
    system("pause");
    return 0;
}
void space(char *p[],int n)
{
    int i,j,k,t;
    for(i=0;i<n;i++){
        for(j=0;p[i][j]!='\0';j++){
            if(p[i][j]==' '&&p[i][j+1]==' '){
                k=j+1;
                while(p[i][k++]==' ');
                k--;
                t=j+1;
                while(p[i][t++]=p[i][k++]);
            }
        }
        if(strlen(p[i])>0){
            printf("%s\n",p[i]);
        }
    }
}