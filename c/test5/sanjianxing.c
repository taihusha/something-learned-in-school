/* 三角形的面积是 ，其中 ，a,b,c为三角形的三边，定义两个带参数的宏，
一个用来求s，另一个用来求area。编写程序，用带参数的宏来计算三角形的面积 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define s(a,b,c) ((a)+(b)+(c))/2
#define area(s,a,b,c) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c))) 
int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(abs(a-b)<c&&abs(b-c)<a&&abs(a-c)<b)
        printf("s=%lf area=%lf",s(a,b,c),area(s(a,b,c),a,b,c));
    else
        printf("Error");
    system("pause");
    return 0;
}