package main

import (
	"fmt"

	"golang.org/x/exp/constraints"
)

func SelectionSort[T constraints.Ordered](arr []T) {
	// arr[0...i) 是有序的；arr[i...n) 是无序的
	for i := 0; i < len(arr); i++ {
		idx := i
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[idx] {
				idx = j
			}
		}
		arr[i], arr[idx] = arr[idx], arr[i]
	}
}

func main() {

	d := []int{1, 2, -3, 4, 9, 10, 10, 20, 6}
	SelectionSort(d)
	fmt.Println(d)

}
