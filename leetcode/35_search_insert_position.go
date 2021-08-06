package main

import (
	"fmt"
)

func searchInsert(nums []int, target int) int {
	start := 0
	end := len(nums) -1
	mid := 0
	for start <= end {
		mid = (start+end)/2
		//fmt.Println(mid)
		if nums[mid] == target {
			return mid
		} else if start == end {
			if nums[start] < target {
				return start + 1
			}
			return start
		} else if nums[mid] < target {
			start = mid + 1
		} else if nums[mid] > target {
			end = mid - 1
		}
	}
	return mid

}

func main() {
	s := []int{1,3,5,6}
	target := 7
	x := searchInsert(s, target)
	fmt.Println(x)
}
