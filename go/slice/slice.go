package main

import (
	"fmt"
)

func f(a [4]int)   { fmt.Println(a) }
func fp(a *[4]int) { fmt.Println(a) }
func main() {
	//var identifier [len]type 声明一个数组的方法
	var arr1 [4]int
	for i := 0; i < len(arr1); i++ {
		arr1[i] = i
	}
	for i, _ := range arr1 {
		fmt.Printf("Array at index %d is %d\n", i, arr1[i])
	}
	//for-range 方式的循环结构
	//第一个返回值 ix 是数组或者切片的索引，第二个是在该索引位置的值；他们都是仅在 for 循环内部可见的局部变量。
	//value 只是 slice1 某个索引位置的值的一个拷贝，不能用来修改 slice1 该索引位置的值。
	for i, value := range arr1 {
		fmt.Printf("Array at index %d is %d\n", i, value)
	}

	//数组的引用方式
	f(arr1)
	fp(&arr1)

	//var identifier []type 声明一个切片的方式
	//一个切片在未初始化之前默认为 nil，长度为 0。

	//切片的初始化格式是：var slice1 []type = arr1[start:end]。
	var slice1 []int = arr1[1:2]

	for i, _ := range slice1 {
		fmt.Printf("Slice at index %d is %d\n", i, slice1[i])
	}
	fmt.Printf("The length of slice1 is %d\n", len(slice1))
	fmt.Printf("The capacity of slice1 is %d\n", cap(slice1))
	fmt.Println("__________")
	//grow slice,又叫切片重组
	//slice1 = slice1[0:end]，其中 end 是新的末尾索引（即长度）
	slice1 = slice1[0:2] //切片只能向后移动，无法获取切片以前的元素

	for i, _ := range slice1 {
		fmt.Printf("Slice at index %d is %d\n", i, slice1[i])
	}
	fmt.Printf("The length of slice1 is %d\n", len(slice1))
	fmt.Printf("The capacity of slice1 is %d\n", cap(slice1))

	//make创建新切片
	//var slice1 []type = make([]type, len)
	//slice1 := make([]type, len)，len 是数组的长度并且也是 slice 的初始长度
	//func make([]T, len, cap)
	//	make([]int, 50, 100)
	//	new([100]int)[0:50]
	//new(T) 为每个新的类型T分配一片内存，初始化为 0 并且返回类型为*T的内存地址：这种方法 返回一个指向类型为 T，值为 0 的地址的指针，
	//它适用于值类型如数组和结构体（参见第 10 章）；它相当于 &T{}。
	//make(T) 返回一个类型为 T 的初始值，它只适用于3种内建的引用类型：切片、map 和 channel（参见第 8 章，第 13 章）。

	//copy函数
	//sl_from := []int{1, 2, 3}
	//sl_to := make([]int, 10)

	//n := copy(sl_to, sl_from)

	//append函数
	//func append(s[]T, x ...T) []T 其中 append 方法将 0 个或多个具有相同类型 s 的元素追加到切片后面并且返回新的切片；
	//追加的元素必须和原切片的元素同类型。如果 s 的容量不足以存储新增元素，append 会分配新的切片来保证已有切片元素和新增元素的存储。
	//因此，返回的切片可能已经指向一个不同的相关数组了。append 方法总是返回成功，除非系统内存耗尽了。
	// 如果你想将切片 y 追加到切片 x 后面，只要将第二个参数扩展成一个列表即可：x = append(x, y...)

}
