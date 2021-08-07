package main

import (
	"fmt"
	"strings"
)

func lengthOfLastWord(s string) int {
	split_stirng := strings.Fields(s)
	result := len(split_stirng[len(split_stirng)-1])
	return result
}

func main()  {
	//s := "   fly me   to   the moon  "
	s := " abx "
	fmt.Println(lengthOfLastWord(s))
}