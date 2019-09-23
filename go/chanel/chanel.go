package main

import (
	"fmt"
	"time"
)

func main() {
	//var identifier chan datatype 声明通道的通常方式
	//由此可知，通道只能传送一种类型的数据，如chan int或chan string
	//通道实际上是类型化消息的队列使数据得以传输。
	//先进先出的结构，引用类型，使用make()函数分配内存

	var ch1 chan string
	ch1 = make(chan string)
	//ch1 := make(chan string)
	buf := 100
	ch2 := make(chan string, buf) //设置一个容量为buf的带缓冲通道
	//在缓冲满载（缓冲被全部使用）之前，给一个带缓冲的通道发送数据是不会阻塞的，
	//而从通道读取数据也不会阻塞，直到缓冲空了

	/*
		通道操作符：<-，信息按照箭头的方向流动

		流向通道（发送）
		ch <- int1 表示：用通道ch发送变量int1
		从通道流出（接收），三种方式
		int2=<-ch 表示：变量int2从通道ch接收数据（若int2未声明，写成 int2 := <-ch
		<- ch 可以单独调用获取通道的（下一个）值，当前值被丢弃，可用于验证

	*/
	/*
		对于同一个通道，发送操作，在接收者准备好之前是阻塞的；如果ch中的数据无人接收就无法再
		给通道传入其他数据：新的输入无法在通道非空的情况下传入。
		对于同一个通道 ，接收操作是阻塞的，直到发送者可用，若通道中无数据则接收者阻塞。
	*/
	/*
		for v := range ch {
		fmt.Printf("The value is %v\n", v)
		}
	*/
	go sendData(ch1)
	go getData(ch1)

	time.Sleep(1e9) //若将此行代码注释之后运行，会发现无字输出，因为没有给予其传递信息的时间
	fmt.Println("over!")
}

func sendData(ch chan string) {
	ch <- "Washington"
	ch <- "Tripoli"
	ch <- "London"
	ch <- "Beijing"
}

func getData(ch chan string) {
	var input string
	for {
		input = <-ch
		fmt.Printf("%s", input)
		fmt.Println()
	}

}
