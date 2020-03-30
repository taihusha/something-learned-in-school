/* 
    传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

    传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

    返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
 
 */
int shipWithinDays(int* weights, int weightsSize, int D){
    int sumWeight=0,maxWeight=weights[0],i;
    for(i=0;i<weightsSize;i++){
        if(maxWeight<weights[i]){
            maxWeight=weights[i];
        }
        sumWeight+=weights[i];
    }
    int avW=sumWeight/weightsSize;
    int left=avW,right=sumWeight;
    if(maxWeight>avW){
        left=maxWeight;
    }
    int days,sum;
    while(left<right){
        int mid=(left+right)/2;
        days=1,sum=0;
        for(i=0;i<weightsSize;i++){
            if(sum+weights[i]>mid){
                sum=0;
                days++;
            }
            sum+=weights[i];
        }
        if(days>D){
            left=mid+1;
        }
        else {
            right=mid;
        }
    }
    return right;
    
}