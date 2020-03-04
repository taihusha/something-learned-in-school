/* 给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，
   
   使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

   如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

   请注意，答案不一定是 arr 中的数字。

 */

#define MMIN(a, b)          ((a) < (b)? (a) : (b))
int findBestValue(int* arr, int arrSize, int target){
    //首先求数组的原始和以及数组最大项的值
    int max=arr[0],i,sum=0;
    for(i=0;i<arrSize;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        sum+=arr[i];
    }
    //若数组长度为1，则知所求值为数组值和target中较小的值
    if(arrSize==1){
        return MMIN(arr[0],target);
    }
    //若数组原始和本就小于等于target，则无法修正，返回数组中最大数的值
    if(sum<=target){
        return max;
    }
    //以1为起始，数组最大值为终值进行二分查找
    int start=1,end=max,temp_sum=0;
    while(end>start){
        int mid=(start+end)/2;
        temp_sum=0;
        //计算当前值的修正和
        for(i=0;i<arrSize;i++){
            temp_sum += (arr[i]>mid) ? mid : arr[i];
        }
        //若当前值仍小于目标值，则左边界右移
        if(target>temp_sum){
            start=mid+1;
        }
        //否则右边界左移
        else if(target<temp_sum){
            end=mid;
        }
        //此时一定满足条件
        else if(target==temp_sum){
            return mid;
        }
    }
     //判断start和start-1
    int sum1=0,sum2=0;
    for(i=0;i<arrSize;i++){
        sum1 += (arr[i]>start) ? start : arr[i];
        sum2 += (arr[i]>start-1) ? (start-1) : arr[i];
    }
    //由于所求值为较小值，故如此设定条件
    if(abs(target-sum1)>=abs(target-sum2)){
        return start-1;
    }
    else {
        return start;
    }  
}