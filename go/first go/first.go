package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	//var num2 string = "1342"
	nums := []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0}
	fmt.Println(jump(nums))
	fmt.Println(myPow(2.0000, 10))
}
func multiply(num1 string, num2 string) string {
	sum, res, temp1, temp2, flag1, flag2 := 0, 0, 0, 0, 0, 0
	var result, nums1, nums2 int
	if len(num1) == 0 || len(num2) == 0 {
		return "0"
	}
	if len(num1) > len(num2) {
		num1, num2 = num2, num1
	}
	for i := len(num1) - 1; i >= 0; i-- {
		nums1 = int(num1[i] - '0')
		for j := len(num2) - 1; j >= 0; j-- {
			nums2 = int(num2[j] - '0')
			res = nums1 * nums2
			temp1 = res%10 + temp2
			temp2 = res / 10
			sum += temp1 * int(math.Pow10(flag1))
			flag1++
		}
		sum += temp2 * int(math.Pow10(flag1))
		flag1 = 0
		result += sum * int(math.Pow10(flag2))
		flag2++
		sum = 0
		temp2 = 0
	}
	return strconv.Itoa(result)
}
func jump(nums []int) int {
	l, res, max, length := len(nums), 0, 0, 0
	if l <= 1 {
		return 0
	}
	for i := 0; i < l; {
		if nums[i]+i >= l-1 {
			return res + 1
		}
		max = 0
		length = 0
		for j := 1; j <= nums[i] && i+j < l; j++ {
			if i+nums[i+j] >= max {
				max = i + nums[i+j]
				length = j
			}
		}
		i += length
		res++
	}
	return res
}

func myPow(x float64, n int) float64 {
	var res float64 = 1
	if n < 0 {
		x = 1 / x
		n = 0 - n
	}
	if n == 0 {
		res = 1
	}
	for ; n > 0; n = n >> 1 {
		if n%2 == 1 {
			res *= x
		}
		x *= x
	}
	return res
}
