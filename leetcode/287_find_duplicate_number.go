package main

import "fmt"

func findDuplicate(nums []int) int {
	check := make([]bool, len(nums))
	for _, value := range nums {
		if check[value-1] {
			return value
		} else {
			check[value-1] = true
		}
	}
	return 0
}

func main(){
	nums := []int{1,3,4,2,2}
	fmt.Println(findDuplicate(nums))
}