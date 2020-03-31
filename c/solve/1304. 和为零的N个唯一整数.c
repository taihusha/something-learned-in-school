/* 
    给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    *returnSize=0;
    int* res = (int*)malloc(sizeof(int) * n);
    int i;
    if(n%2!=0){
        res[(*returnSize)++]=0;
        for(i=1;i<=(n-1)/2;i++){
            res[(*returnSize)++]=i;
            res[(*returnSize)++]=-i;
        }
    }
    else {
        for(i=1;i<=n/2;i++){
            res[(*returnSize)++]=i;
            res[(*returnSize)++]=-i;
        }
    }
    return res;
}