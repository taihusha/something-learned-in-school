/* 
    给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

    说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* majorityElement(int* nums, int numsSize, int* returnSize){
    //根据条件可判断其中众数最多只有2个，利用摩尔投票法定义两个变量
    
    *returnSize=0;
    if(numsSize==0){
        return returnSize;
    }
    int* res = (int*)malloc(sizeof(int) * 2);
    
    int res1=0,res2=9;
    int times1=0,times2=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==res1){
            times1++;
        }
        else if(nums[i]==res2){
            times2++;
        }
        else if(times1==0){
            res1=nums[i];
            times1=1;
        }
        else if(times2==0){
            res2=nums[i];
            times2=1;
        }
        else {
            times1--;
            times2--;
        }
    }
    times1=0,times2=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==res1) times1++;
        else if(nums[i]==res2) times2++;
    }
    if(times1>numsSize/3) res[(*returnSize)++]=res1;
    if(times2>numsSize/3) res[(*returnSize)++]=res2;
    return res;
    
}