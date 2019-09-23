package main

import "fmt"

type struct1 struct {
	i1  int
	f1  float32
	str string
}

//type identifier struct {
//    field1 type1
//    field2 type2
//    ...
//}声明方法

//一些常见结构体
//链表
/* type Node struct {
	su *Node
	data float64
} */
//二叉树
/* type Tree struct {
	le *Tree
	data float64
	ri *Tree
} */

//结构体工厂，尽量避免new的使用使私有化
type File struct {
	fd   int    // 文件描述符
	name string // 文件名
}

//结构体可以包含一个或多个 匿名（或内嵌）字段，即这些字段没有显式的名字，只有字段的类型是必须的，此时类型就是字段的名字。
//匿名字段本身可以是一个结构体类型，即 结构体可以包含内嵌结构体。
/* type innerS struct {
	in1 int
	in2 int
}
由此可见一个结构体中只能有一种数据类型的匿名字段
type outerS struct {
	b    int
	c    float32
	int  // anonymous field
	innerS //anonymous field
} */
func main() {
	ms := new(struct1)
	ms.i1 = 10
	ms.f1 = 15.5
	ms.str = "Chris"

	fmt.Printf("The int is: %d\n", ms.i1)
	fmt.Printf("The float is: %f\n", ms.f1)
	fmt.Printf("The string is: %s\n", ms.str)
	fmt.Println(*ms)

	f := NewFile(10, "./test.txt") //调用方法
}
func NewFile(fd int, name string) *File {
	if fd < 0 {
		return nil
	}

	return &File{fd, name}
}
