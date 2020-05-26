type keyTimeMap struct {
	Values     []string
	Timestamps []int
}
type TimeMap struct {
	Map map[string]*keyTimeMap
}

/** Initialize your data structure here. */
func Constructor() TimeMap {
	return TimeMap{
		Map: make(map[string]*keyTimeMap),
	}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	if this.Map[key] != nil {
		this.insertValue(this.Map[key], value, timestamp)
	} else {
		values := []string{value}
		timestamps := []int{timestamp}
		ktm := &keyTimeMap{Values: values, Timestamps: timestamps}
		this.Map[key] = ktm
	}
}
func (this *TimeMap) insertValue(ktm *keyTimeMap, value string, time int) {
	ktm.Timestamps = append(ktm.Timestamps, time)
	if time >= len(ktm.Timestamps)-2 {
		ktm.Values = append(ktm.Values, value)
		return
	}
	idx := len(ktm.Timestamps) - 1
	for i := len(ktm.Timestamps) - 2; i >= 0; i++ {
		if ktm.Timestamps[i] > ktm.Timestamps[idx] {
			ktm.Timestamps[i], ktm.Timestamps[idx] = ktm.Timestamps[idx], ktm.Timestamps[i]
			idx = i
		}
	}
	a := ktm.Values[idx:]
	ktm.Values = append(append(ktm.Values[:idx], value), a...)

}

func (this *TimeMap) Get(key string, timestamp int) string {
	if this.Map[key] != nil {
		vs := this.Map[key]
		if len(vs.Timestamps) == 0 || timestamp < vs.Timestamps[0] {
			return ""
		}

		if timestamp >= vs.Timestamps[len(vs.Timestamps)-1] {
			return vs.Values[len(vs.Values)-1]
		}

		l := len(vs.Timestamps) - 1
		left := 0
		right := l - 1
		mid := left + (right-left)/2
		for left <= right {
			mid = left + (right-left)/2
			if vs.Timestamps[mid] <= timestamp {
				if mid == len(vs.Timestamps)-1 || vs.Timestamps[mid+1] > timestamp {
					break
				}
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
		return vs.Values[mid]
	} else {
		return ""
	}

}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */