package main

import (
	"fmt"
	"regexp"
)

func main() {
	bufSlice := []string{"222@11.com", "22211.com"}

	pat := ".*@.*.com"
	for _, val := range bufSlice {
		if ok, _ := regexp.Match(pat, []byte(val)); ok {
			fmt.Println("Match Found!")
		} else {
			fmt.Println("Match Not Found!")
		}
	}
}
