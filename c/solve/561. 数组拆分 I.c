/*
	给定长度为 2n 的数组, 你的任务是将这些数分成 n 对,

	例如 (a1, b1), (a2, b2), ..., (an, bn) ，

	使得从1 到 n 的 min(ai, bi) 总和最大。

*/
void quickSort(int *p,int n,int r)
{
 if(n<r)
    {
        int q=partion(p,n,r);
        quickSort(p,n,q-1);
        quickSort(p,q+1,r);
    }
}
int partion(int *p,int s,int e)
{
    int x=p[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(p[j]<=x)
        {
            i=i+1;
            int temp1=p[i];
            p[i]=p[j];
            p[j]=temp1;
        }
    }
    int temp2=p[i+1];
    p[i+1]=p[e];
    p[e]=temp2;
    return i+1;
}
int arrayPairSum(int* nums, int numsSize){
    quickSort(nums,0,numsSize-1);
    int res=0;
    for(int i=0,index=0;i<numsSize/2;i++){
        res+=nums[index];
        index+=2;
    }
    return res;
}