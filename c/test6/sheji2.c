/* 设某个班有N个学生，每个学生修了M门课程（用#define定义N、M）。
输入M门课程的名称，然后依次输入N个学生中每个学生所修的M门课程的成绩并且都存放到相应的数组中。
编写下列函数：
a.计算每个学生各门课程平均成绩；
b.计算全班每门课程的平均成绩；
c.分别统计低于全班各门课程平均成绩的人数；
d.分别统计全班各门课程不及格的人数和90分以上（含90分）的人数。
在调用函数中输出上面各函数的计算结果。（要求都用指针操作，不得使用下标操作。）
 */
#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 2
int main()
{
    char course[M][30],student[N][30];
    float grades[N][M];
    int num_c,num_s;
    char *pc=&course[0][0];
    char *ps=&student[0][0];
    float *pg=&grades[0][0];
    for(num_c=0;num_c<M;num_c++){//课程的初始化
        printf("please enter the %d course's name:\n",num_c+1);
        scanf("%s",course[num_c]);
    }
    for(num_s=0;num_s<N;num_s++){//学生的初始化
        printf("please enter the %d student's name:\n",num_s+1);
        scanf("%s",student[num_s]);
    }
    for(num_s=0;num_s<N;num_s++){//成绩的初始化
        printf("please enter student %s 's grade\n",student[num_s]);
        for(num_c=0;num_c<M;num_c++){
            printf("please enter %s 's grade:\n",course[num_c]);
            scanf("%f",&grades[num_s][num_c]);
        }
    }
    float sum=0;
    for(num_s=0;num_s<N;num_s++){//计算每个学生各门课程平均成绩
        sum=0;
        printf("%s 's courses' average grade is:\n",ps+num_s*30);
        for(num_c=0;num_c<M;num_c++) sum+=*(pg+num_s*M+num_c);
        printf("%f\n",sum/M);
    }
    float sum_all=0;
    for(num_c=0;num_c<M;num_c++){//计算全班每门课程的平均成绩
        sum_all=0;
        printf("%s's course's average grade of the class is:\n",pc+num_c*30);
        for(num_s==0;num_s<N;num_s++) sum_all+=*(pg+num_s*M+num_c);
        printf("%f\n",sum/N);
    }
    for(num_c=0;num_c<M;num_c++){//分别统计低于全班各门课程平均成绩的人数
        sum_all=0;
        printf("the num of who's grade is lower than %s 's average grade is:\n",pc+num_c*30);
        int count=0;
        for(num_s=0;num_s<N;num_s++)
        {
            if(*(pg+num_s*M+num_c)<sum/N) count++;
        }
        printf("%d\n",count);
        count=0;
    }
    for(num_c=0;num_c<M;num_c++){//统计全班各门课程不及格的人数的人数
        printf("as for %s,the num of who's grade is lower than 60 is:\n",pc+num_c*30);
        int count=0;
        for(num_s=0;num_s<N;num_s++){
            if(*(pg+num_s*M+num_c)<60) count++;
        }
        printf("%d\n",count);
        count=0;
    }
    for(num_c=0;num_c<M;num_c++){//统计全班各门课程90分以上（含90分）的人数
        printf("as for %s,the num of who's grade is higher than 90 is:\n",pc+num_c*30);
        int count=0;
        for(num_s=0;num_s<N;num_s++){
            if(*(pg+num_s*M+num_c)>=90) count++;
        }
        printf("%d\n",count);
        count=0;
    }
    system("pause");
    return 0;
}