/*  （1）修改程序，使程序编译通过且能运行；
	（2）单步执行。进入函数decimal_fraction时watch窗口中x为何值？在返回main时, watch窗口中i为何值？
    输入r为3，此时x为28.2743092;i=28
	（3）排除错误，使程序能正确输出面积s值的整数部分，不会输出错误信息assertion failed。
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define  R
int integer_fraction(float);
int  main()
{
    float  r, s;
    int s_integer=0;
    printf ("input a number: ");
    scanf("%f",&r);
    #ifdef  R
       s=3.14159*r*r;
       printf("area of round is: %f\n",s);
       s_integer= integer_fraction(s);
       printf("the integer fraction of area is %d\n", s_integer);
       assert((s-s_integer)<1.0);
    #endif
    system("pause");
    return 0;
}

int integer_fraction(float x)
{
  int i=x;
  return i;
}

