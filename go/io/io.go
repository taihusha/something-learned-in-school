package main

import (
	"bufio"
	"fmt"
)

var (
	firstName, lastName, s string
	i                      int
	f                      float32
	input1                 = "56.12 / 5212 / Go"
	format                 = "%f / %d / %s"
)

var inputReader *bufio.Reader
var input2 string
var err error

func main() {
	//由于某种不可察的原因似乎无法正常使用其输入功能，故将这段代码暂时封印
	//使用 bufio 包提供的缓冲读取（buffered reader）来读取数据
	/* 	inputReader = bufio.NewReader(os.Stdin)
	   	fmt.Println("Please enter some input: ")
	   	input2, err = inputReader.ReadString('\n')
	   	if err == nil {
	   		fmt.Printf("The input was: %s\n", input2)
	   	} */
	//使用 fmt 包提供的 Scan 和 Sscan 开头的函数
	fmt.Sscanf(input1, format, &f, &i, &s)
	fmt.Println("From the string we read: ", f, i, s)
	// 输出结果: From the string we read: 56.12 5212 Go
	fmt.Println("Please enter your full name: ")
	//fmt.Scanln(&firstName, &lastName)
	fmt.Scanf("%s %s", &firstName, &lastName)
	fmt.Printf("Hi %s %s!\n", firstName, lastName) // Hi Chris Naegels

}
