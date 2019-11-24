#include "stdio.h"
#include<stdlib.h>
#define SUM ((a)+(b))
#define DIF ((a)-(b))
#define SWAP(a,b)  a^=b,b^=a,a^=b
int main()
{
    int a,b,t;
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM, SUM*DIF);
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);
    system("pause");
    return 0;
}

