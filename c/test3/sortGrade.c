/* 输入n个学生的姓名和C语言课程的成绩，将成绩按从高到低的次序排序，
姓名同时作相应调整，输出排序后学生的姓名和C语言课程的成绩。
然后，输入一个C语言课程成绩值，用二分查找进行搜索。
如果查找到有该成绩，输出该成绩同学的姓名和C语言课程的成绩；
否则输出提示“not found!”。 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char [][20],int [],int);
void search(char [][20],int [],int);
int main()
{
    int i,num;
    printf("Please enter students num\n");
    scanf("%d",&num);
    int grade[num];
    char name[num][20];
    for(i=0;i<num;i++)
    {
        printf("input student name:");
        scanf("%s",&name[i]);
        printf("input grade:");
        scanf("%d",&grade[i]);
    }
    sort(name,grade,num);
    for(i=0;i<num;i++)
    {
        printf("student name:%s,    grade:%d\n",name[i],grade[i]);
    }
    search(name,grade,num);
    system("pause");
    return 0;
}
void sort(char n[][20],int g[],int num)
{
  int i, j, t;
  char a[20]={'\0'};
  for (i = 0; i < num - 1; i++)
    for ( j = 0; j < num - i - 1; j++)
        if(g[j] > g[j+1])
        {
            t = g[j], g[j] = g[j+1], g[j+1] = t;
            strcpy(a,n[j]),strcpy(n[j],n[j+1]),strcpy(n[j+1],a);
        }
}
void search(char n[][20],int g[],int num)
{
    int grade,flag=0;
    printf("input the grade:");
    scanf("%d",&grade);
    int s=0,e=num,mid;
    while (s<e)
    {
        mid=(s+e)/2;
        if(grade=g[mid])
        {
            printf("student name:%s,    grade:%d\n",n[mid],g[mid]);
            flag=1;
            break;
        }
        else if (grade>g[mid])
        {
            s=mid+1;
        }
        else if (grade<g[mid])
        {
            e=mid;
        }
    }
    if(flag==0)
    {
        printf("not found");
    }
    
}