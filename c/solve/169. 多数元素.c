/* 
    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 */
//暴力求解、分治、哈希表、排序、随机化
//Boyer-Moore Majority Vote Algorithm
int majorityElement(int* nums, int numsSize){
    int target=nums[0],times=1;
    int i;
    for(i=1;i<numsSize;i++){
        if(times==0){
            target=nums[i];
            times++;
        }
        else
        {
            if(target==nums[i]){
                times++;
            }
            else {
                times--;
            }
        }
        
    }
    return target;
}
