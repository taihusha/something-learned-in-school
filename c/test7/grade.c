/* 用单向链表建立一张班级成绩单，
包括每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计四门课程的成绩。
用函数编程实现下列功能：
(1) 输入每个学生的各项信息。 
(2) 输出每个学生的各项信息。
(3) 修改指定学生的指定数据项的内容。
(4) 统计每个同学的平均成绩（保留2位小数）。
(5) 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    long num;//学号
    char s[10];//姓名
    int g_e;//英语成绩
    int g_m;//数学成绩
    int g_p;//物理成绩
    int g_c;//c成绩
    struct student *next;
};
void creatList(struct student **headp);//输入每个学生的各项信息
void outputList(struct student **headp);//输出每个学生的各项信息
void correctList(struct student **headp);//修改指定学生的指定数据项的内容
void avStudent(struct student **headp);//统计每个同学的平均成绩（保留2位小数）
void sumStudent(struct student **headp);//输出各位同学的学号、姓名、四门课程的总成绩和平均成绩
int main(){
    struct student *head=NULL;
    creatList(&head);
    outputList(&head);
    correctList(&head);
    avStudent(&head);
    sumStudent(&head);
    system("pause");
    return 0;
}
void creatList(struct student **headp){
    *headp=(struct student *)malloc(sizeof(struct student));
    struct student *tail=*headp,*p=*headp;
    printf("please input the following item divided by square:\n");
    printf("num\tname\tEnglish_grade\tmath_grade\tphysics_grade\tc_grade");
    printf("end with 0\n");
    for(;;){
        scanf("%ld",&p->num);
        if(p->num==0)break;
        scanf("%s%d%d%d%d",p->s,&p->g_e,&p->g_m,&p->g_p,&p->g_c);
        p=(struct student *)malloc(sizeof(struct student));
        tail->next=p;
        tail=p;
    }
    tail->next=NULL;
}
void outputList(struct student **headp){
    struct student *p=*headp;
    while (p->next!=NULL)
    {
        printf("num %ld name %s ENG %d MATH %d PHY %d C %d\n",p->s,p->g_e,p->g_m,p->g_p,p->g_c);
        p=p->next;
    }
    
}
void correctList(struct student **headp){
    struct student *p=*headp;
    printf("please input the name\n");
    char n[10];
    scanf("%s",n);
    for(;p->next!=NULL&&strcmp(p->s,n);p=p->next)
    ;
    if(!strcmp(p->s,n)){
       printf("find num %ld name %s ENG %d MATH %d PHY %d C %d\n",p->s,p->g_e,p->g_m,p->g_p,p->g_c);
    }
    else if(p->next==NULL){
        printf("not found\n");
        return;
    }
    printf("which to change?\n");
    printf("1:num\n");
    printf("2:name\n");
    printf("3:ENG\n");
    printf("4:MATH\n");
    printf("5:PHY\n");
    printf("6:C\n");
    char c=getchar();
    printf("please reinput\n");
    switch (c)
    {
    case '1':
        scanf("%ld",&p->num);
        break;
    case '2':
        scanf("%d",&p->s);
        break;
    case '3':
        scanf("%d",&p->g_e);
        break;
    case '4':
        scanf("%d",&p->g_m);
        break;
    case '5':
        scanf("%d",&p->g_p);
        break;
    case '6':
        scanf("ld",&p->g_c);
        break;
    
    default:
        break;
    }
    return;
}
void avStudent(struct student **headp){
    struct student *p=*headp;
    for(;p->next!=NULL;p=p->next){
        double tp;
        tp=(p->g_e+p->g_m+p->g_p+p->g_c)/4.0;
        printf("num %ld name %s average grade is %.2lf\n",p->num,p->s,tp);
    }
}
void sumStudent(struct student **headp){
    struct student *p=*headp;
    for(;p->next!=NULL;p=p->next){
        double tp;
        int sum;
        sum=p->g_e+p->g_m+p->g_p+p->g_c;
        tp=sum/4.0;
        printf("num %ld name %s average grade is %.2lf,sum grade is %d\n",p->num,p->s,tp,sum);
    }
}