/* 
    给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
    
    你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k*k 个积分。
    
    当你将所有盒子都去掉之后，求你能获得的最大积分和。

 */
int max(int a,int b){
    return (a>b)? a:b;
}
int removeBoxes(int* boxes, int boxesSize){
    int n=boxesSize;
    //建立一个三维的dp数组记录状态
    int dp[101][101][101]={0};
    int i,j,k,t,m,res;
    for(i=0;i<n;i++){
        for(k=0;k<i;k++){
            dp[i][i][k]=(k+1)*(k+1);
        }
    }
    for ( t = 0; t < n; t++) {
        for ( j = t; j < n; j++) {
            i = j - t;
            for (k = 0; k <= i; k++) {
                 res = (1 + k) * (1 + k) + dp[i + 1][j][0];
                for ( m = i + 1; m <= j; m++) {
                    if (boxes[m] == boxes[i]) {
                        res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                }
                dp[i][j][k] = res;
            }
        }
    }
    return n == 0 ? 0 : dp[0][n - 1][0];    
}