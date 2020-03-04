//编写函数strnins(s,t,n),其功能是：可将字符数组 t中的字符串插入到字符数组 s中字符串的第n个字符的后面
#include<stdio.h>
#include<stdlib.h>
int Queen8();
int main()
{
    Queen8();
    system("pause");
    return 0;
}
int Queen8()
{
    int count = 0;
    for(int q1=0;q1<8;q1++)
    {
        for(int q2=0;q2<8;q2++)
        {
            if(q1==q2 || q1+1==q2 || q1-1==q2)
            {
                continue;
            }
            for(int q3=0;q3<8;q3++)
            {
                if(q1==q3 || q1+2==q3 || q1-2==q3 ||
                   q2==q3 || q2+1==q3 || q2-1==q3)
                {
                    continue;
                }
                for(int q4=0;q4<8;q4++)
                {
                    if(q1==q4 || q1+3==q4 || q1-3==q4 ||
                       q2==q4 || q2+2==q4 || q2-2==q4 ||
                       q3==q4 || q3+1==q4 || q3-1==q4)
                    {
                        continue;
                    }
                    for(int q5=0;q5<8;q5++)
                    {
                        if(q1==q5 || q1+4==q5 || q1-4==q5 ||
                           q2==q5 || q2+3==q5 || q2-3==q5 ||
                           q3==q5 || q3+2==q5 || q3-2==q5 ||
                           q4==q5 || q4+1==q5 || q4-1==q5 )
                        {
                            continue;
                        }
                        for(int q6=0;q6<8;q6++)
                        {
                            if(q1==q6 || q1+5==q6 || q1-5==q6 ||
                               q2==q6 || q2+4==q6 || q2-4==q6 ||
                               q3==q6 || q3+3==q6 || q3-3==q6 ||
                               q4==q6 || q4+2==q6 || q4-2==q6 ||
                               q5==q6 || q5+1==q6 || q5-1==q6)
                            {
                                continue;
                            }
                            for(int q7=0;q7<8;q7++)
                            {
                                if(q1==q7 || q1+6==q7 || q1-6==q7 ||
                                   q2==q7 || q2+5==q7 || q2-5==q7 ||
                                   q3==q7 || q3+4==q7 || q3-4==q7 ||
                                   q4==q7 || q4+3==q7 || q4-3==q7 ||
                                   q5==q7 || q5+2==q7 || q5-2==q7 ||
                                   q6==q7 || q6+1==q7 || q6-1==q7)
                                {
                                    continue;
                                }
                                for(int q8=0;q8<8;q8++)
                                {
                                    if(q1==q8 || q1+7==q8 || q1-7==q8 ||
                                       q2==q8 || q2+6==q8 || q2-6==q8 ||
                                       q3==q8 || q3+5==q8 || q3-5==q8 ||
                                       q4==q8 || q4+4==q8 || q4-4==q8 ||
                                       q5==q8 || q5+3==q8 || q5-3==q8 ||
                                       q6==q8 || q6+2==q8 || q6-2==q8 ||
                                       q7==q8 || q7+1==q8 || q7-1==q8)
                                    {
                                        continue;
                                    }
                                    printf("%d,%d,%d,%d,%d,%d,%d,%d\n",
                                        q1,q2,q3,q4,q5,q6,q7,q8);
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return count;
}
