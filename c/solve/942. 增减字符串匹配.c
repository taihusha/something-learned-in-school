/* 
    给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。

    返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：


        如果 S[i] == "I"，那么 A[i] < A[i+1]
        如果 S[i] == "D"，那么 A[i] > A[i+1]

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
    int len=strlen(S);
    *returnSize=0;
    int min=0,max=len;
    int* res = (int*)malloc(sizeof(int) * (len+1));
    for(int i=0;i<len;i++){
        if(S[i]=='I'){
            res[(*returnSize)++]=min;
            min++;
        }
        else {
            res[(*returnSize)++]=max;
            max--;
        }
    }
    res[(*returnSize)++]=min;
    return res;
    
}