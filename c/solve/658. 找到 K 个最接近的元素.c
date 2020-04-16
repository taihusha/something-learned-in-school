/* 
    给定一个排序好的数组，两个整数 k 和 x，
    
    从数组中找到最靠近 x（两数之差最小）的 k 个数。

    返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    int *res;
    *returnSize=k;
    if(arr==NULL||arrSize==0||k==0){
        return NULL;
    }
    res=(int *)malloc(sizeof(int)*(k));
    int left=0,right=arrSize-k;
    int tmp;
    while(left<right) {
        int mid=(left+right)/2;
        if(x-arr[mid]>arr[mid+k]-x) {
            left=mid+1;
        }
        else {
            right=mid;
        }
    }
    return &arr[left];
}