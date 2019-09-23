package main

import "fmt"

type Shaper interface {
	Area() float32
}

type Square struct {
	side float32
}
type Rectangle struct {
	length, width float32
}

func (sq *Square) Area() float32 { //实现了接口Shaper的方法Area()
	return sq.side * sq.side
}
func (re Rectangle) Area() float32 {
	return re.length * re.width
}

var i = 5
var str = "ABC"

type Person struct {
	name string
	age  int
}

type Any interface{} //空接口

func main() {
	r := Rectangle{5, 3} // Area() of Rectangle needs a value
	q := &Square{5}      // Area() of Square needs a pointer
	shapes := []Shaper{r, q}
	fmt.Println("Looping through shapes for area ...")
	for n, _ := range shapes {
		fmt.Println("Shape details: ", shapes[n])
		fmt.Println("Area of this shape is: ", shapes[n].Area())
	}

	sq1 := new(Square)
	sq1.side = 5

	var areaIntf Shaper
	areaIntf = sq1 //可将Square sq1赋给Shaper areaIntf
	// shorter,without separate declaration:
	// areaIntf := Shaper(sq1)
	// or even:
	// areaIntf := sq1
	fmt.Printf("The square has area: %f\n", areaIntf.Area())

	if t, ok := areaIntf.(*Square); ok {
		fmt.Printf("The type of areaIntf is: %T\n", t)
	}
	if u, ok := areaIntf.(Rectangle); ok {
		fmt.Printf("The type of areaIntf is: %T\n", u)
	} else {
		fmt.Println("areaIntf does not contain a variable of type Circle")
	} //类型断言，用以判断接口当时的动态呈现

	/* 	假定 v 是一个值，然后我们想测试它是否实现了 Stringer 接口
	    type Stringer interface {
			String() string
		}

		if sv, ok := v.(Stringer); ok {
			fmt.Printf("v implements String(): %s\n", sv.String()) // note: sv, not v
		} */
	var val Any
	val = 5
	fmt.Printf("val has the value: %v\n", val)
	val = str
	fmt.Printf("val has the value: %v\n", val)
	pers1 := new(Person)
	pers1.name = "Rob Pike"
	pers1.age = 55
	val = pers1
	fmt.Printf("val has the value: %v\n", val)
	switch t := val.(type) { //类型断定的一种
	case int:
		fmt.Printf("Type int %T\n", t)
	case string:
		fmt.Printf("Type string %T\n", t)
	case bool:
		fmt.Printf("Type boolean %T\n", t)
	case *Person:
		fmt.Printf("Type pointer to Person %T\n", t)
	default:
		fmt.Printf("Unexpected type %T", t)
	}
}
