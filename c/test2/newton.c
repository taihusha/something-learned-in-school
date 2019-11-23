//用牛顿迭代法求方程f(x)=3x3-4x3-5x+13=0满足精度e=10-6的一个近似根，并在屏幕上输出所求近似根。
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define percise 0.000001
double func1(double x);
void NewtonMethod(double x);
int main() 
{
    NewtonMethod(1);
    system("pause");
    return 0;
}
double func1(double x){//原函数
   return -(x*x*x)-5*x+13;
}
double func2(double x){//导函数
    return -3*(x*x)-5;
}
void NewtonMethod(double x){

    int i=0;

    printf("-----------------NewtonMethod-------------------\n");

    printf("The original value is%f\n",x);

    while(fabs(func1(x)/func2(x))>percise){

        x-=func1(x)/func2(x);

        i++;

        printf("number:%d,and now the x is%f\n",i,x);

    }

    printf("The final result is%f\n",x);

}