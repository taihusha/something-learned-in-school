#include<stdio.h>
#include<stdlib.h>
int a;
int b=10;
int count(int num);
int print();
int main()
{
        int c=count(b);
        int a=2;
        printf("num is %d\n",print());
        return 0;
}
int count(int num)
{
        return num+10;
}
int print()
{
        return b;
}