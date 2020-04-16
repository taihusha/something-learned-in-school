/*
你在进行一个简化版的吃豆人游戏。你从 (0, 0) 点开始出发，你的目的地是 (target[0], target[1]) 。

地图上有一些阻碍者，第 i 个阻碍者从 (ghosts[i][0], ghosts[i][1]) 出发。

每一回合，你和阻碍者们*可以*同时向东，西，南，北四个方向移动，每次可以移动到距离原位置1个单位的新位置。

如果你可以在任何阻碍者抓住你之前到达目的地（阻碍者可以采取任意行动方式），

则被视为逃脱成功。如果你和阻碍者同时到达了一个位置（包括目的地）都不算是逃脱成功。

当且仅当你有可能成功逃脱时，输出 True。
*/
func abs(num int) int {
	if num < 0 {
		return -1 * num
	}
	return num
}
func escapeGhosts(ghosts [][]int, target []int) bool {
	dis := abs(target[0]) + abs(target[1])
	for i := 0; i < len(ghosts); i++ {
		temp := abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1])
		if temp <= dis {
			return false
		}
	}
	return true
}