//编写一个程序,从键盘读取数据，对一个3´4矩阵进行赋值，求其转置矩阵，然后输出原矩阵和转置矩阵
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int matrix[3][4];
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Printf original matrix\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("Printf zhuanzhi matrix\n");
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}