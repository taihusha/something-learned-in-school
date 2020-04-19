/*
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。

返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。
*/
func numTilePossibilities(tiles string) int {
	tile := make([]int, 26)
	res := 0
	for _, ch := range tiles {
		tile[ch-'A']++
	}
	traceback(tile, &res)
	return res
}
func traceback(tile []int, result *int) {
	for i := 0; i < 26; i++ {
		if tile[i] <= 0 {
			continue
		}
		tile[i]--
		(*result)++
		traceback(tile, result)
		tile[i]++
	}
}