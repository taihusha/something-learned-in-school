//给定一个二进制数组，求使其中元素全为0或1的最小翻转次数
package main

import "fmt"

func main() {
	testArray := []int{0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0}
	flip(testArray)
}
func flip(array []int) {
	n := len(array)
	for i := 1; i < n; i++ {
		if array[i] != array[i-1] {
			if array[i] != array[0] {
				fmt.Print("from\t", i, "\tto\t")
			} else {
				fmt.Println(i - 1)
			}
		}
	}
	if array[n-1] != array[0] {
		fmt.Println(n - 1)
	}
}
