//将用户输入的任意正整数逆转，例如，输入1234，输出4321
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int num,num_copy,res,temp;
    scanf("%d",&num);
    res=0;
    num_copy=num;
    while (num_copy>0)
    {
        temp=num_copy%10;
        num_copy=num_copy/10;
        res=res*10+temp;
    }
    printf("%d's resver is %d\n",num,res);
    system("pause");
    return 0;
}