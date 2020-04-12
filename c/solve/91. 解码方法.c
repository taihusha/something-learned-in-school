/* 
    一条包含字母 A-Z 的消息通过以下方式进行了编码：

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26


    给定一个只包含数字的非空字符串，请计算解码方法的总数。

 */
int numDecodings(char * s){
    //s[i]为0,不可单独编码
    /*否则,
        若s[i-1]满足构成二字符编码条件，且长度大于2，则dp[i]=dp[i-2]+dp[i]
        若不满足，则加一种编码方式
    */
    int len=strlen(s);
    int dp[len];//以下标i为结尾的编码总数
    memset(dp, 0, sizeof(dp));
    int i;
    dp[0] = (*s=='0')?0:1;
    for(i=1;i<len;i++){
        if(s[i]!='0') {
            dp[i]=dp[i-1];
        }
        if(s[i-1]=='1' || (s[i-1]=='2'&&s[i]<'7')){
            if(i-2>=0){
                dp[i]+=dp[i-2];
            }
            else {
                dp[i]++;
            }
        }
    }
    return dp[len-1];
    
}