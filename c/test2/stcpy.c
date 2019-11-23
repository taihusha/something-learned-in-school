//编写一个程序,将输入的一行字符复制到输出，复制过程中将一个以上的空格字符用一个空格代替
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    char s[200];
    printf("[Please enter the string]\n");
    gets(s);
    printf("%s\n",s);
    char res[200];
    for(int i=0,j=0;i<200;)
    {
        
        if(i>0&&s[i]==' '&&s[i-1]==' ')
        {
            i++;
            continue;
        }
        else
        {
            res[j]=s[i];
            i++;
            j++;
        }
        
    }
    printf("%s\n",res);
    system("pause");
    return 0;
}