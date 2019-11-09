func subsets(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	var res [][]int
	var elem []int
	subsetsTrace(&res, nums, elem, 0)
	return res
}
func subsetsTrace(res *[][]int, nums, elem []int, start int) {
	tmp := make([]int, len(elem))
	copy(tmp, elem)
	*res = append(*res, tmp)
	for i := start; i < len(nums); i++ {
		elem = append(elem, nums[i])
		subsetsTrace(res, nums, elem, i+1)
		elem = elem[:len(elem)-1]
	}
}