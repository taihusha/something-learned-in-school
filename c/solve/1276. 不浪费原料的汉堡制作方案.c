/*
	给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：
		巨无霸汉堡：4 片番茄和 1 片奶酪
		小皇堡：2 片番茄和 1 片奶酪

	请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，

	使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize){
    int m=tomatoSlices,n=cheeseSlices;
    if(m%2!=0||2*n>m||4*n<m){
        *returnSize=0;
        return NULL;
    }
    int*res=(int*)malloc(2*sizeof(int));
    res[0]=(m/2)-n;
    res[1]=2*n-(m/2);
    *returnSize=2;
    return res;
}