#include "stdio.h"
#include<stdlib.h>
long fabonacci(int n);
/* （1）刚执行完scanf("%d",&k);语句，p,i值是多少？
0x61ff10,4194432
（2）从fabonacci函数返回后光条停留在哪个语句上？
 sum+=fabonacci(i);
（3）进入fabonacci函数时，watch窗口显示的是什么？
显示fabonacci函数的局部变量n的值
（4）当i=3时，从调用fabonacci函数到返回，n值如何变化？	 
1->2->3->2->1
*/
//其中，long sum=0,*p=&sum;声明p为长整型指针并用&sum取出sum的地址对p初始化。*p表示引用p所指的变量（*p即sum）。
int main()
{
    int i,k;
    long sum=0,*p=&sum;
    char *s;
    scanf("%s",&s);
    printf("%s",s);
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        sum+=fabonacci(i);
        printf("i=%d\tthe sum is %ld\n",i,*p);
    }
    system("pause");
    return 0;
}
long fabonacci(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fabonacci(n-1)+fabonacci(n-2);
}
