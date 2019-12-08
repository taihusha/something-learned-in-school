/* 设有N位整数和M位小数（N=20，M=10）的数据a,b。编程计算a+b并输出结果。
如：12345678912345678912.1234567891 + 98765432109876543210.0123456789
 */
#include<stdio.h>
#include<stdlib.h>
#define N 20
#define M 10
int main(){
    int i;
    int *pa,*pb,*ps,a[N+M],b[N+M],sum[N+M+1];
    printf("input a:\n");
    for(i=0;i<N+M;i++){
        scanf("%d",a[i]);
    }
    printf("input b:\n");
    for(i=0;i<N+M;i++){
        scanf("%d",b[i]);
    }
    int num,flag=0;
    for(i=N+M-1;i>=0;i--){
        num=a[i]+b[i]+flag;
        flag=num/10;
        num=num%10;
        sum[i+1]=num;
    }
    system("pause");
    return 0;
}