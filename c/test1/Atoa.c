#include<stdio.h>
#include<stdlib.h>
int main() {
   /*  编写一个程序，输入字符ｃ，
    如果ｃ是大写字母，则将ｃ转换成对应的小写，
    否则ｃ的值不变，最后输出ｃ */
    char ch;
    printf("Input the char C\n");
    scanf("%c",&ch);
    if(ch>='A'&&ch<='Z'){
        ch=ch-'0'+32+'0';
        printf("the char is %c\n",ch);
    }
    else if(ch>='a'&&ch<='z'){
        printf("the char is %c\n",ch);
    }
    else{
        printf("input error");
    }
    system("pause");
    return 0;
}