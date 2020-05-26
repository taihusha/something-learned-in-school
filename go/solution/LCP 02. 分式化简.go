func fraction(cont []int) []int {
	res := make([]int, 2)
	son, mom := 1, cont[len(cont)-1]
	for i := len(cont) - 2; i >= 0; i-- {
		son += mom * cont[i]

		tmp := mom
		mom = son
		son = tmp
	}
	res[0] = mom
	res[1] = son
	return res
}

//简化后
func fraction(cont []int) []int {
	son, mom := 0, 1
	for i := len(cont) - 1; i >= 0; i-- {
		mom, son = mom*cont[i]+son, mom
	}
	return []int{mom, son}
}