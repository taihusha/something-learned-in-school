/*
 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
*/
import "fmt"

func summaryRanges(nums []int) []string {
	l, r := 0, 0
	var res []string
	for r < len(nums) {
		for r < len(nums)-1 && nums[r+1]-nums[r] == 1 {
			r++
		}
		if l != r {
			res = append(res, fmt.Sprintf("%d->%d", nums[l], nums[r]))
		} else {
			res = append(res, fmt.Sprintf("%d", nums[r]))
		}
		r++
		l = r
	}
	return res
}