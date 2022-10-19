package main

import "fmt"

type User struct {
	id   int
	name string
}

type Manager struct {
	User
}

func (self *User) ToString() string {
	return fmt.Sprintf("User: %p, %v", self, self)
}

func (self *User) Run1() {
	for i := 1; i < 10; i++ {
		fmt.Println(i)
	}
}

func (self User) Run2() {
	for i := 10; i < 20; i++ {
		fmt.Println(i)
	}
}

// 如果Manager 包含 User字段(或者*User)，则Manager和*Manager包含所有的User* 和 User的所有字段
func main() {
	m := Manager{User{1, "rcf"}}
	fmt.Printf("Manager: %p\n", &m)
	fmt.Println(m.ToString())
	&m.Run1()
	m2 := &m
	m2.Run2()
}
