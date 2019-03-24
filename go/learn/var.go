package main

import "fmt"

//变量的声明

//第一种，指定变量类型，声明后若不赋值予默认值
//var identifier type
//v_name = value

//第二种，根据值自行判断变量类型
//var v_name = value

//第三种 省略var.P.S.:=左侧的变量不应该是已经声明过的，否则会导致编译错误
//P.S 该种方法仅能在函数体中使用
//v_name:=value

//多变量声明
//var vname1,vname2,vname3 type
//vname1,vname2,vname3= v1,v2,v3
//var vname1, vname2, vname3 = v1, v2, v3 ||和python很像,不需要显示声明类型，自动推断
//vname1, vname2, vname3 := v1, v2, v3 ||出现在:=左侧的变量不应该是已经被声明过的，否则会导致编译错误

// 这种因式分解关键字的写法一般用于声明全局变量
/*var (
    vname1 v_type1
    vname2 v_type2
)*/
var a = "wei hongxv"
var b string = "hust"
var c bool
var (
	e int
	f string
)

func main() {
	//函数体内局部变量的声明
	//	var a string = "abc"
	d := 10
	//	g, h := 26, "hello"
	fmt.Println("hello")
}
