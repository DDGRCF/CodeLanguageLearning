package main

import (
	"fmt"
)

func main() {
	mapTest := make(map[string]int)
	mapTest["rcf"] = 25
	mapTest["wjb"] = 26
	for k, v := range mapTest {
		fmt.Printf("key: %v, value: %v\n", k, v)
	}

	mapTest = map[string]int{
		"wjb": 25,
		"rcf": 24,
	}

	for k, v := range mapTest {
		fmt.Printf("key: %v value: %v\n", k, v)
	}

	sliceTest := make([]int, 5, 10)

	for i, _ := range sliceTest {
		sliceTest[i] = i // range 时是拷贝直接使用v = xxx 是无效的
	}

	for i, v := range sliceTest {
		fmt.Printf("index: %v value: %v\n", i, v)
	}

	sliceTest = []int{
		2, 3, 4, 5,
	}

	for i, v := range sliceTest {
		fmt.Printf("index: %v value: %v\n", i, v)
	}

	sliceTest = append(sliceTest, 2, 4)

	for i, v := range sliceTest {
		fmt.Printf("index: %v value: %v\n", i, v)
	}

}
