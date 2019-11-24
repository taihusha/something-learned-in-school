//输入一个整数，将它在内存中二进制表示的每一位转换成为对应的数字字符，存放到一个字符数组中，然后输出该整数的二进制表示
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    int i,t,s=0;
    char ch[50];
    scanf("%d",&num);
    for(;num!=0;s++)
    {
        i=num%2;
        num=num/2;
        ch[s]=i;
    }
    for(t=s-1;t>=0;t--)
    {
        printf("%4d",ch[t]);
    }
    system("pause");
    return 0;
}