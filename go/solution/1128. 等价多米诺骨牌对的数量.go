/*
	给你一个由一些多米诺骨牌组成的列表 dominoes。

	如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

	形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

	在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

*/
type Domino struct {
	a int
	b int
}

func numEquivDominoPairs(dominoes [][]int) int {
	dominomap := make(map[Domino]int)
	res := 0
	for _, d := range dominoes {
		if d[0] > d[1] {
			temp := d[0]
			d[0] = d[1]
			d[1] = temp
		}
		domino := Domino{
			a: d[0],
			b: d[1],
		}
		if _, ok := dominomap[domino]; !ok {
			dominomap[domino] = 1
		} else {
			dominomap[domino]++
		}
	}
	for _, val := range dominomap {
		res += val * (val - 1) / 2
	}
	return res
}