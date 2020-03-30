/*
    给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

    Note: The returned array must be malloced, assume caller calls free().
*/
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int i=0,num = 0;
    //将数组中数字异或，所得结果为a,b两数的异或结果，对其中非0位进行分析
    for(i=0;i<numsSize;i++){
        num^=nums[i];
    }
    num=num&(~num+1);
    int* res=(int*)malloc(sizeof(int) * 2);
    res[0]=res[1]= 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i]&num) {
            res[0]^=nums[i];
        }
        else {
	        res[1]^=nums[i];
	    }
    }
    *returnSize = 2;
    return res;
}