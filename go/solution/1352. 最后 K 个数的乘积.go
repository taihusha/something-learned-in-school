/*
	请你实现一个「数字乘积类」ProductOfNumbers，要求支持下述两种方法：
		1. add(int num)
			将数字 num 添加到当前数字列表的最后面。

		2. getProduct(int k)
			返回当前数字列表中，最后 k 个数字的乘积。
			你可以假设当前列表中始终 至少 包含 k 个数字。

	题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit 整数范围内，不会溢出。
*/
type ProductOfNumbers struct {
	Nums []int
	Top  int
}

func Constructor() ProductOfNumbers {
	return ProductOfNumbers{
		Nums: make([]int, 0),
		Top:  -1,
	}
}

func (this *ProductOfNumbers) Add(num int) {
	this.Nums = append(this.Nums, num)
	this.Top++
}

func (this *ProductOfNumbers) GetProduct(k int) int {
	res, top := 1, this.Top
	for i := 0; i < k; i++ {
		res *= this.Nums[top]
		top--
	}
	return res
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */