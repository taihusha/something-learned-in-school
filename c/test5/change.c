//（1）对这个例子程序进行调试修改，使之能够正确完成指定任务；
//（2）用带参数的宏替换函数max，来实现求最大数的功能。

#include<stdio.h>
#include<stdlib.h>
#define max1(a,b,c) (((a)>(b)?(a):(b))>(c))?((a)>(b)?(a):(b)):(c)
float sum(float, float);
int max(int,int,int);
int  main()
{
    int a, b, c;
    float d, e;
    printf("Enter three integers:");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nthe maximum of them is %d\n",max1(a,b,c));

    printf("Enter two floating point numbers:");
    scanf("%f%f",&d,&e);
    printf("\nthe sum of them is  %f\n",sum(d,e));
    system("pause");
    return 0;

}

int max2(int x, int y, int z)
{
   int t;
   if (x>y)
     t=x;
   else
     t=y;
   if (t<z)
     t=z;
   return t;
}

float sum(float x, float y)
{
  return x+y;
}
