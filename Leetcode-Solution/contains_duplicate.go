package main

import "fmt"

func containsDuplicate(nums []int) bool {
	mp := make(map[int]bool)
	for i := 0; i<len(nums); i++ {
		if _, exist := mp[nums[i]]; exist {
			return true
		} else {
			mp[nums[i]] = true
		}
	}
	return false
}

// func main()  {
// 	var a []int
// 	a = make([]int, 4)
// 	a [0] = 1
// 	a [1] = 2
// 	a [2] = 3
// 	a [3] = 1
// 	r := containsDuplicate(a)
// 	fmt.Println(r)

// }
