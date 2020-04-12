/*
   在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，

   他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。

   现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。

   你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。

*/
func findPoisonedDuration(timeSeries []int, duration int) int {
	sum := 0
	if len(timeSeries) == 0 {
		return 0
	}
	for i := 0; i < len(timeSeries)-1; i++ {
		if timeSeries[i+1]-timeSeries[i] < duration {
			sum += timeSeries[i+1] - timeSeries[i]
		} else {
			sum += duration
		}
	}
	return sum + duration
}