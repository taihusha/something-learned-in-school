func groupAnagrams(strs []string) [][]string {
	map1 := make(map[byte]int){'a':2,'b':3,'c':5,'d':7,'e':11,'f':13,'g':17,'h':19,'i':23,'j':29,'k':31,'l':37,'m':41,'n':43,'o':47,'p':53,'q':59,'r':61,'s':67,'t':71,'u':73,'v':79,'w':83,'x':89,'y':97,'z':101}
	var num,count int=1,0
	var res [][]string
	map2 :=make(map[int]int)
	for i:=0;i<len(strs);i++ {
		num=1
		for j,ch :=range strs[i] {
			num*=map1[ch]
		}
		if _,ok:=map2[num];!ok {
			map2[num]=count
			count++
			res=append(res,[]string{})
		}
		res[map2[num]]=append(res[map2[num]],strs[i])

    }
}