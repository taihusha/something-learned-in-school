/* 
	给定一个已排序的正整数数组 nums，和一个正整数 n 。

	从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。

	请输出满足上述要求的最少需要补充的数字个数。

 */
 func minPatches(nums []int, n int) int {
    //nums->1-n
    sort.Ints(nums)
    miss,res,index:=1,0,0
    for miss<=n {
        if index<len(nums) && nums[index]<=miss {
            miss+=nums[index]
            index++
        } else {
            miss+=miss
            res++
        }
    }
    return res
}
