#include<stdio.h>
#include<stdlib.h>
int main()
{
    float var;
    float *p=&var;
    scanf("%f",p);
    printf("%f\n",*p);
    system("pause");
    return 0;    
}
