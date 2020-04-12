/*
   在显示着数字的坏计算器上，我们可以执行以下两种操作：


       双倍（Double）：将显示屏上的数字乘 2；
       递减（Decrement）：将显示屏上的数字减 1 。


   最初，计算器显示数字 X。

   返回显示数字 Y 所需的最小操作数。

*/
func brokenCalc(X int, Y int) int {
	res := 0
	for X < Y {
		if Y%2 == 0 {
			Y /= 2
			res++
		} else {
			Y = (Y + 1) / 2
			res += 2
		}
	}
	return res + X - Y
}