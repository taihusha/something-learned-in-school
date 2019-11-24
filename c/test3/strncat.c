//函数strncat(s,t,n)本来应该将字符数组t的前n个字符连接到字符数组s中字符串的尾部
/* （1） 单步执行源程序。进入函数strncat后观察表达式s、t和i。
      当光条落在for语句所在行时，i为何值？i=23.
      当光条落在strncat函数块结束标记（右花括号 }）所在行时, s、t分别为何值？
      s:0x61feee "The adopted symbol is",t:0x61fed3 "abcdefghijklmnopqrstuvwxyz".
（2）分析函数出错的原因，排除错误，使函数正确实现功能，最后写出程序的输出结果。 
    i在递增时多加了1使开始加的地方落在'\0'后面，而printf函数在输出时遇见'\0'直接结束了。
*/

#include<stdio.h>
#include<stdlib.h>
void strncat(char [],char [],int);
int main(void)
{
    char a[50]="The adopted symbol is ",b[27]="abcdefghijklmnopqrstuvwxyz";
    strncat(a, b, 4);
    printf("%s\n",a);
    system("pause");
    return 0;
}
void strncat(char s[],char t[], int n)
{
    int i = 0, j;
    while(s[i++]);
    i--;
    for(j = 0; j < n && t[j];)
        s[i++] = t[j++];
    s[i] = '\0';
}
