/*
集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，

导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，

导致集合丢失了一个整数并且有一个元素重复。

给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，

再找到丢失的整数，将它们以数组的形式返回。

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize=2;
    int *result=(int*)malloc(2*sizeof(int));
    int *count=calloc(numsSize+1,sizeof(int));
    int i,sum=0;
    for(i=0;i<numsSize;i++)
    {
        count[nums[i]]++;
        if(2==count[nums[i]])
        {
            result[0]=nums[i];//出现次数为2的为重复的数
        }
        sum=sum+nums[i];
    }
    result[1]=numsSize*(numsSize+1)/2-(sum-result[0]);//正常和减去无重复集的和为缺失的数
    return result;
}