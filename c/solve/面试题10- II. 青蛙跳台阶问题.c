/* 
    一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 */
int numWays(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    int dp[2];
    dp[0]=1;
    dp[1]=1;
    int i,tmp;
    for(i=2;i<=n;i++){
        dp[0]=(dp[0]+dp[1])%1000000007;
        tmp=dp[1],dp[1]=dp[0],dp[0]=tmp;
    }
    return dp[1];
}