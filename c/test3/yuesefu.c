//M个人围成一圈，从第一个人开始依次从1至N循环报数，每当报数为N时报数人出圈，直到圈中只剩下一个人为止
#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 3
int main()
{
    int a[M]={0}, b[M];	/* 数组a存放圈中人的编号，数组b存放出圈人的编号 */
    int i, j, k;
    for(i = 0; i < M; i++)			/* 对圈中人按顺序编号1—M */
        a[i] = i + 1;
    for(i = M, j = 0; i > 1; i--)
    {
/* i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置 */
        for(k = 1; k <= N; k++)			/* 1至N报数 */
            if(++j > i - 1) j = 0;/* 最后一个人报数后第一个人接着报，形成一个圈 */
                b[M-i] = j?a[j-1]:a[i-1];	/* 将报数为N的人的编号存入数组b */
            if(j)
                for(k = --j; k < i; k++)	/* 压缩数组a，使报数为N的人出圈 */
                    a[k]=a[k+1];
    }
    // 标记法
/*     for(i=M,j=0;i>0;i--)
    {
        for(k=1;k<=N;k++)
        {
            if(++j>M-1)j=0;
            if((j==0&&a[9]==1)||(j!=0&&a[j-1]==1))k=k-1;
        }
        b[M-i]=j?j:M;
        a[j-1]=1;
        for(i=0;i<M;i++)  // 按次序输出出圈人的编号 
        printf("%6d", b[i]);
    }
     */
     
    for(i=0;i<M-1;i++)  /* 按次序输出出圈人的编号 */
        printf("%6d", b[i]);
    printf("%6d\n", a[0]);			/* 输出圈中最后一个人的编号 */
    system("pause");
    return 0;
}
