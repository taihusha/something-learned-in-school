package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	/* HasPrefix 判断字符串 s 是否以 prefix 开头：
	   strings.HasPrefix(s, prefix string) bool
	   HasSuffix 判断字符串 s 是否以 suffix 结尾：
	   strings.HasSuffix(s, suffix string) bool */
	var strs string = "This is an example of a string"
	fmt.Printf("T/F? Does the string \"%s\" have prefix %s? ", strs, "Th")
	fmt.Printf("%t\n", strings.HasPrefix(strs, "Th"))
	/*
	   Index 返回字符串 str 在字符串 s 中的索引（str 的第一个字符的索引），-1 表示字符串 s 不包含字符串 str：
	   strings.Index(s, str string) int
	   LastIndex 返回字符串 str 在字符串 s 中最后出现位置的索引（str 的第一个字符的索引），-1 表示字符串 s 不包含字符串 str：
	   strings.LastIndex(s, str string) int
	   如果需要查询非 ASCII 编码的字符在父字符串中的位置，建议使用以下函数来对字符进行定位：
	   strings.IndexRune(s string, r rune) int */
	var str string = "Hi, I'm Marc, Hi."

	fmt.Printf("The position of \"Marc\" is: ")
	fmt.Printf("%d\n", strings.Index(str, "Marc"))

	fmt.Printf("The position of the first instance of \"Hi\" is: ")
	fmt.Printf("%d\n", strings.Index(str, "Hi"))
	fmt.Printf("The position of the last instance of \"Hi\" is: ")
	fmt.Printf("%d\n", strings.LastIndex(str, "Hi"))

	fmt.Printf("The position of \"Burger\" is: ")
	fmt.Printf("%d\n", strings.Index(str, "Burger"))

	/* Count 用于计算字符串 str 在字符串 s 中出现的非重叠次数：
	   strings.Count(s, str string) int */
	var str1 string = "Hello, how is it going, Hugo?"
	var manyG = "gggggggggg"
	fmt.Printf("Number of H's in %s is: ", str1)
	fmt.Printf("%d\n", strings.Count(str, "H"))

	fmt.Printf("Number of double g's in %s is: ", manyG)
	fmt.Printf("%d\n", strings.Count(manyG, "gg"))
	/* Repeat 用于重复 count 次字符串 s 并返回一个新的字符串：
	   strings.Repeat(s, count int) string */
	var origS string = "Hi there! "
	var newS string

	newS = strings.Repeat(origS, 3)
	fmt.Printf("The new repeated string is: %s\n", newS)
	/* 	ToLower 将字符串中的 Unicode 字符全部转换为相应的小写字符：
	   	strings.ToLower(s) string
		ToUpper 将字符串中的 Unicode 字符全部转换为相应的大写字符：
		strings.ToUpper(s) string */
	var orig string = "Hey, how are you George?"
	var lower string
	var upper string

	fmt.Printf("The original string is: %s\n", orig)
	lower = strings.ToLower(orig)
	fmt.Printf("The lowercase string is: %s\n", lower)
	upper = strings.ToUpper(orig)
	fmt.Printf("The uppercase string is: %s\n", upper)
	/* 使用strings.TrimSpace(s) 来剔除字符串开头和结尾的空白符号；
	   如果你想要剔除指定字符，则可以使用 strings.Trim(s, "cut")
	   来将开头和结尾的 cut 去除掉。该函数的第二个参数可以包含任何字符，
	   如果你只想剔除开头或者结尾的字符串，则可以使用 TrimLeft 或者 TrimRight 来实现。
	   strings.Fields(s) 将会利用 1 个或多个空白符号来作为动态长度的分隔符将字符串分割成若干小块，
	   并返回一个 slice，如果字符串只包含空白符号，则返回一个长度为 0 的 slice。
		strings.Split(s, sep) 用于自定义分割符号来对指定字符串进行分割，同样返回 slice。 */
	/* strconv.Itoa(i int) string 返回数字 i 所表示的字符串类型的十进制数。
	   strconv.FormatFloat(f float64, fmt byte, prec int, bitSize int) string
	   将 64 位浮点型的数字转换为字符串，其中 fmt 表示格式（其值可以是 'b'、'e'、'f' 或 'g'），
		prec 表示精度，bitSize 则使用 32 表示 float32，用 64 表示 float64。
		strconv.Atoi(s string) (i int, err error) 将字符串转换为 int 型。
		strconv.ParseFloat(s string, bitSize int) (f float64, err error) 将字符串转换为 float64 型。 */
	var origs string = "666"
	var an int
	var newSs string

	fmt.Printf("The size of ints is: %d\n", strconv.IntSize)

	an, _ = strconv.Atoi(origs)
	fmt.Printf("The integer is: %d\n", an)
	an = an + 5
	newSs = strconv.Itoa(an)
	fmt.Printf("The new string is: %s\n", newSs)
}
