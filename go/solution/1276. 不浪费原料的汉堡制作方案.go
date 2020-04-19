/*
	给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：
		巨无霸汉堡：4 片番茄和 1 片奶酪
		小皇堡：2 片番茄和 1 片奶酪

	请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，

	使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。
*/
func numOfBurgers(tomatoSlices int, cheeseSlices int) []int {
	//4x+2y=tomato,x+y=cheese
	var res []int
	jumbo_2 := tomatoSlices - 2*cheeseSlices
	if jumbo_2%2 == 0 && jumbo_2 >= 0 && cheeseSlices-jumbo_2/2 >= 0 {
		res = append(res, jumbo_2/2)
		res = append(res, cheeseSlices-jumbo_2/2)

	}
	return res
}