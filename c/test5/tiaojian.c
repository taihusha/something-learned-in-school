/* 用条件编译方法来编写程序。输入一行电报文字，可以任选两种输出：一为原文输出；
二为变换字母的大小写（如小写‘a’变成大写‘A’，大写‘D’变成小写‘d’），其他字符不变。
用#define命令控制是否变换字母的大小写。
例如，#define CHANGE 1 则输出变换后的s文字，若#define CHANGE 0则原文输出 */
#include<stdio.h>
#include<stdlib.h>
#define CHANGE 1
int main()
{
    char c;
    printf("please input the paragraph\n");
    while((c=getchar())!=EOF)
    {
        #if CHANGE
        {
            if(c>='A'&&c<='Z')
                putchar(c+32);
            else if (c>='a'&&c<='z')
                putchar(c-32);
            else
                putchar(c);            
        }
        #else
        {
            putchar(c);
        }
        #endif
    }
    system("pause");
    return 0;
}