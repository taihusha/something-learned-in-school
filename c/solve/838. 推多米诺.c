/* 
    一行中有 N 张多米诺骨牌，我们将每张多米诺骨牌垂直竖立。

    在开始时，我们同时把一些多米诺骨牌向左或向右推。

    每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。

    同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

    如果同时有多米诺骨牌落在一张垂直竖立的多米诺骨牌的两边，由于受力平衡， 该骨牌仍然保持不变。

    就这个问题而言，我们会认为正在下降的多米诺骨牌不会对其它正在下降或已经下降的多米诺骨牌施加额外的力。

    给定表示初始状态的字符串 "S" 。如果第 i 张多米诺骨牌被推向左边，则 S[i] = 'L'；如果第 i 张多米诺骨牌被推向右边，则 S[i] = 'R'；如果第 i 张多米诺骨牌没有被推动，则 S[i] = '.'。

    返回表示最终状态的字符串。

 */
//硬推
char * pushDominoes(char * dominoes){
    int i,lastL=-1,lastR=-1,k;
    for(i=0;dominoes[i]!='\0';i++){
        if(dominoes[i]=='L'){
            if(lastR<0){
                k=i;
                while(k>=0) dominoes[k--]='L';
            }
            else if(lastR<lastL){
                k=i;
                while(k>=lastL) dominoes[k--]='L';
            }
            else {
                int k1=lastR,k2=i;
                while(k1<k2){
                    dominoes[k1++]='R';
                    dominoes[k2--]='L';
                }
            }
            lastL=i;
        }
        else if(dominoes[i]=='R'){
            if(lastR>lastL){
                k=lastR;
                while(k<i) dominoes[k++]='R';
            }
            lastR=i;
        }
    }
    if(lastR>lastL){
        k=lastR;
        while(dominoes[k]!='\0') dominoes[k++]='R';
    }
    return dominoes;
}
//动态规划
char * pushDominoes(char * dominoes){
    int len=strlen(dominoes);
    int dp[len],i,j;
    for (i = 0; i < len; i++){
        if(dominoes[i]=='L') dp[i]=-1;
        else if(dominoes[i]=='R') dp[i]=1;
        else dp[i]=0;
    }
    for(i = 0; i < len ; i++){
        if(dp[i]>0 && i+1<len-1) dp[i+1]=dp[i]+1;
        j=i;
        while(dp[j]<0 && j-1 >= 0 && (dp[j-1]+dp[j]>0 || dp[j-1]==0 )){
            if(dp[j-1]+dp[j]==1){
                dp[j-1]=0;
                break;
            }
            else
            {
                dp[j-1]=dp[j]-1;
            }
            
        }
    }
    for (int i = 0; i < len; i++) dominoes[i]=(dp[i] > 0 ? 'R' : dp[i] < 0 ? 'L' : '.');
    return dominoes;
}