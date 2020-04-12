/* 
    把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

    你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* twoSum(int n, int* returnSize){
    //投出数的范围：n-6*n
    double* res = (double*)malloc(sizeof(double) * (5*n+1));
    *returnSize=0;
    int i,j;
    int dp[12][75];//第一维表示投掷了i粒骰子，第二维表示某点数，值表示出现次数
     memset(dp, 0, sizeof(dp));
    //初始化
    for(i=1;i<=6;i++) {
        dp[1][i]=1;
    }
    for(i=2;i<=n;i++) {
        for(j=i;j<=6*i;j++){
           for (int cur = 1; cur <= 6; cur ++) {
               if (j - cur <= 0) {
                    break;
                }
                dp[i][j] += dp[i-1][j-cur];
            }
        }
    }
    int all=pow(6,n);
    for (i = n; i <= 6 * n; i ++) {
        res[(*returnSize)++]= (dp[n][i]*1.0/all);
    }
    return res;
}