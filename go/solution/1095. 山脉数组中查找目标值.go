/*
（这是一个 交互式问题 ）

给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。

*/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */

func findInMountainArray(target int, mountainArr *MountainArray) int {
	//find peak
	l := mountainArr.length()
	s, e := 0, l-1
	peak := -1
	for s < e {
		mid := (s + e) / 2
		if mid == 0 {
			mid += 1
			e += 1
		}
		if mid == l-1 {
			s -= 1
			mid -= 1
		}
		lower, tar, higher := mountainArr.get(mid-1), mountainArr.get(mid), mountainArr.get(mid+1)
		if tar > lower && tar > higher {
			peak = mid
			break
		} else if tar < higher && tar > lower {
			if lower == target {
				return mid - 1
			} else if tar == target {
				return mid
			} else if higher == target {
				return mid + 1
			}
			s = mid + 1
		} else if tar < lower && tar > higher {
			e = mid - 1
		}
	}
	//  return peak
	if peak == -1 {
		peak = s
	}
	//find target
	s1, e1 := 0, peak
	s2, e2 := peak+1, l-1
	for s1 <= e1 {
		mid := (s1 + e1) / 2
		index := mountainArr.get(mid)
		if index > target {
			e1 = mid - 1
		} else if index < target {
			s1 = mid + 1
		} else {
			return mid
		}
	}
	for s2 <= e2 {
		mid := (s2 + e2) / 2
		index := mountainArr.get(mid)
		if index > target {
			s2 = mid + 1
		} else if index < target {
			e2 = mid - 1
		} else {
			return mid
		}
	}
	return -1
}