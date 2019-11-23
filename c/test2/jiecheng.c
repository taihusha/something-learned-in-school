#include <stdio.h>
#include<stdlib.h>
int main()
{
    //计算s=n! 
    int i,j,k,n;
    long s;
    printf("Please enter n:");
    scanf("%d",&n); 
    //for
    s=1;
    for(i=1;i<=n;i++){
        s=s*i;
    }
    printf("for %d! = %d\n",n,s);
    //do-while
    j=1,s=1;
    do
    {
        s=s*j;
        j++;
    } while (j<=n);  
    printf("do-while %d! = %d\n",n,s);
    //while
    k=1,s=1;
    while (k<=n)
    {
        s=s*k;
        k++;
    } 
    printf("while %d! = %d\n",n,s);

    //输入改为“整数S”，输出改为“满足n！≥S的最小整数n”
    printf("Please enter S:");
    scanf("%d",&s);
    n=1;
    int mul=1;
    do
    {
        n++;
        mul*=n;
    } while (mul<s);
    
    printf("the min num is %d",n);
    system("pause");
    return 0;
}

