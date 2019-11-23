#include<stdio.h>
#include<stdlib.h>
int zuidagongyue(int a,int b);
//执行过程：a:32,b:20->a:20,b:32->a:12,b:20->a:8,b:12->a:4,b:8->return 4
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int res=zuidagongyue(a,b);
    printf("the result is %d\n",res);
    system("pause");
    return 0;
}
int zuidagongyue(int a,int b)
{
    int temp=a;
    if(b%a==0)
        return a;
    else
        return zuidagongyue(b%a,a);
}