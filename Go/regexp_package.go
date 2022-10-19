package main

import (
	"fmt"
	"regexp"
)

func main() {
	bufSlice := []string{"222@11.com", "22211.com"}
	bufSlice2 := []string{"1234a_aa", "2434dfdsf@"}

	pat := "^[A-Za-z0-9\u4e00-\u9fa5]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$"
	for _, val := range bufSlice {
		if ok, _ := regexp.MatchString(pat, val); ok {
			fmt.Println("Match Found!")
		} else {
			fmt.Println("Match Not Found!")
		}
	}

	pat2 := "^[A-Za-z0-9@]{9,16}$"
	for _, val := range bufSlice2 {
		if ok, _ := regexp.MatchString(pat2, val); ok {
			fmt.Println(val + " Match Found!")
		} else {
			fmt.Println(val + " Match Not Found!")
		}
	}
}
