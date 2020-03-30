/* 
    给定一个无序的整数数组，找到其中最长上升子序列的长度。 
*/
int lengthOfLIS(int* nums, int numsSize){
    int res[numsSize+1];//下标表示存放当前长度时的最大元素
    int i,max=0;
    res[0]=INT_MIN;
    if(numsSize<=1){
        return numsSize;
    }
    for(i=0;i<numsSize;i++){
        if(res[max]<nums[i]){//表示当前元素要比最大序列的元素要大，直接加一
            res[++max]=nums[i];
        }
        else {//否则在之前维护的数组中尝试找一个比num大的数进行替换
            int low = 1, high = max, mid;
            while(low < high)
            {
                mid = low + (high - low) / 2;
                if(res[mid] < nums[i]) low = mid + 1;
                else high = mid;
            }
            res[low] = nums[i];
        }
    }
    return max;
}