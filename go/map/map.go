package main

import (
	"fmt"
)

func main() {
	//var map1 map[keytype]valuetype
	//var map1 map[string]int
	var mapLit map[string]int // map 可以用 {key1: val1, key2: val2} 的描述方法来初始化，就像数组和结构体一样。
	//var mapCreated map[string]float32
	var mapAssigned map[string]int
	//map 的初始化：var map1 = make(map[keytype]valuetype)。
	//或者简写为：map1 := make(map[keytype]valuetype)。
	//不要使用 new，永远用 make 来构造 map
	//make(map[keytype]valuetype, cap) 初始化时可以通过设置cap来设置map的最大值
	mapLit = map[string]int{"one": 1, "two": 2}
	mapCreated := make(map[string]float32)
	mapAssigned = mapLit
	//mapAssigned 也是 mapList 的引用，对 mapAssigned 的修改也会影响到 mapLit 的值。
	mapCreated["key1"] = 4.5
	mapCreated["key2"] = 3.14159
	mapAssigned["two"] = 3

	fmt.Printf("Map literal at \"one\" is: %d\n", mapLit["one"])
	fmt.Printf("Map created at \"key2\" is: %f\n", mapCreated["key2"])
	fmt.Printf("Map assigned at \"two\" is: %d\n", mapLit["two"])
	fmt.Printf("Map literal at \"ten\" is: %d\n", mapLit["ten"])

	//val1, isPresent = map1[key1] ，可用来判断某个键值在map中是否存在

	//isPresent 返回一个 bool 值：
	//如果 key1 存在于 map1，val1 就是 key1 对应的 value 值，并且 isPresent为true；
	//如果 key1 不存在，val1 就是一个空值，并且 isPresent 会返回 false。

}
