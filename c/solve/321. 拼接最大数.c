/* 
    给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，

    表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，

    要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

    求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
 //执行失败...
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaxArr(int* nums,int numsSize,int arrSize,int* res){
    for(int i=0;i<arrSize;i++){
        res[i]=0;
    }
    for(int i=0,j=0;i<numsSize;i++){
        while(numsSize-i+j>arrSize&&j>0&&nums[i]>res[j-1]) j--;
        if(j<arrSize) res[j++]=nums[i];
    }
    return res;
}
bool compare(int* nums1,int i,int nums1Size,int* nums2,int j,int nums2Size){
    while(i<nums1Size && j<nums2Size && nums1[i]==nums2[j]){
        i++;
        j++;
    }
    return j==nums2Size || (i<nums1Size && nums1[i]>nums2[j]);
}
int merge(int* nums1, int nums1Size, int* nums2, int nums2Size,int k,int* res){
    int i,j,r,sum=0;
    for(i=0,j=0,r=0;r<k;r++)
        res[r]=compare(nums1,i,nums1Size,nums2,j,nums2Size)?nums1[i++]:nums2[j++];
    return sum;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize){
    int i;
    for(i=0;i<k;i++){
        returnSize[i]=0;
    }
    //nums1中选取i个数，nums2中选取k-i个数组成解
    for(i=(k-nums2Size>0)?(k-nums2Size):0;i<k&&i<nums1Size;i++){
        int res1[i];
        int res2[k-i];
        int arr[k];
        //在nums1中找i个数可构成最大子序列的解
        getMaxArr(nums1,nums1Size,i,res1);
        //在nums2中找k-i个数可构成最大子序列的解
        getMaxArr(nums2,nums2Size,k-i,res2);
        //记录暂时的最大值
        merge(nums1,nums1Size,nums2,nums2Size,k,arr);
       if(compare(arr,0,k,returnSize,0,k)) returnSize=arr;
    }
    //根据最大值构建数组
    return returnSize;
}
