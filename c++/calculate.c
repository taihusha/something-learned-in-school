
#include <cstdio>
//#include<stdio.h>
#include <cmath>

#define percise 0.00000001
#define PI 3.14159265358979
 

double func1(double x){//原函数

   return 2*sin(x+PI/3)-x;

}

double func2(double x){//导数

    return 2*cos(x+PI/3)-1;

}

void dichotomy(double x,double y){

    double middle=(x+y)/2;

    int i=0;

    printf("-----------------_-------------------\n");

    printf("original:left%f,right%f\n",x,y);

    while(fabs(func1(middle))>percise){

        func1(middle)*func1(x)>0?x=middle:y=middle;

        middle=(x+y)/2;

        i++;

        printf("nums:%d,left%f,right%f\n",i,x,y);

    }

    printf("result%f\n",middle);

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

void NewtonDownMethod(double x){

    int i=0;

    double x1,u=1;

    printf("---------------牛顿下山法------------------\n");

    printf("初始值为%f\n",x);

    while(fabs(func1(x)/func2(x))>percise){

        u=1;

        x1=x-u*func1(x)/func2(x);

        if(fabs(func1(x1))>=fabs(func1(x)))

             u*=0.5;

        i++;

        printf("迭代次数为:%d,此时x为%f,x1为%f,u为%f\n",i,x,x1,u);

        x=x1;

    }

    printf("最终结果为%f\n",x);

}

void SecantMethod(double x,double y){

    int i=0;

    printf("-----------------弦割法-------------------\n");

    while(fabs(func1(x)*(y-x)/(func1(y)-func1(x)))>percise){

        x-=func1(x)*(y-x)/(func1(y)-func1(x));

        i++;

        printf("迭代次数为:%d,此时x为%f\n",i,x);

    }

    printf("最终结果为%f\n",x);

}

void picard(double x){
	int i=0;
	while((func1(x)-x)>percise){
		x=func1(x);
		i++;
		printf("num:%d,x:%f\n",i,x);
	}
	printf("result%f\n",x);
}
int main() {

 //   dichotomy(0,1,1);
//	dichotomy(0,1,0);//用二分法求两个方程的解
//      picard(0.5);
    NewtonMethod(1);
//NewtonMethod(2,0);//用牛顿法求两个方程的解

 //   NewtonDownMethod(-32,1);NewtonDownMethod(-11,0);//用牛顿下降法求两个方程的解

//    SecantMethod(-10,1,1);SecantMethod(-10,1,0);//用弦割法求两个方程的解
system("pause");
    return 0;

}
