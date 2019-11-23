#include "stdio.h"
#include<stdlib.h>
double sum_fac1(int n);
long sum_fac2(int n);
int main()
{
    //计算s=1!+2!+3!+…+n!
    int k;
    for(k=1;k<6;k++)
         printf("k=%d\tthe sum is %ld\n",k,sum_fac2(k)); 
    for(k=1;k<6;k++)
         printf("k=%d\tthe sum is %lf\n",k,sum_fac1(k));
    system("pause");
    return 0;
}
double sum_fac1(int n)
{
    
    int i;
    double s=0;
    double fac=1;
    for(i=1;i<=n;i++)
    {
        fac*=(double)1/i;
        s+=fac;
    }
    return s;
}
long sum_fac2(int n)
{
    int i;
    long s=0;   
    long fac=1;
    for(i=1;i<=n;i++)
    {
        fac*=i;
        s+=fac;
    }
    return s;
}
