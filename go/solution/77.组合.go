func combine(n int, k int) [][]int {
	if n == 0 || k == 0 {
		return [][]int{}
	}
	var res [][]int                   //结果数组
	var elem []int                    //当前数组
	combineTrace(elem, 1, n, k, &res) //适配leetcode
	return res
}
func combineTrace(elem []int, start, n, k int, res *[][]int) {
	if len(elem) == k {
		tmp := make([]int, k)
		copy(tmp, elem)
		*res = append(*res, tmp)
	}
	for i := start; i < n+1; i++ {
		//选取一个元素加入当前数组
		elem = append(elem, i)
		//从下一个数字开始进行递归回溯
		combineTrace(elem, i+1, n, k, res)
		//递归调用结束之后将之前放入的数字移除
		elem = elem[:len(elem)-1]
	}
}