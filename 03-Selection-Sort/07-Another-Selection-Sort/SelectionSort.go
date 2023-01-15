package main

import (
	"fmt"
	"log"
	"math/rand"
	"time"

	"golang.org/x/exp/constraints"
)

func SelectionSort[T constraints.Ordered](arr []T) {
	// arr(i, n-1] 是有序的；arr[0, i] 是无序的
	for i := len(arr) - 1; i >= 0; i-- {
		idx := i
		for j := i - 1; j >= 0; j-- {
			if arr[j] > arr[idx] {
				idx = j
			}
		}
		arr[i], arr[idx] = arr[idx], arr[i]
	}
}

func generateRandomArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = rand.Int()
	}
	return arr
}

func isSorted[T constraints.Ordered](arr []T) bool {
	for i := 0; i < len(arr)-1; i++ {
		if arr[i] > arr[i+1] {
			return false
		}
	}
	return true
}

func main() {
	start := time.Now()
	d := generateRandomArray(50000)
	SelectionSort(d)
	if isSorted(d) {
		fmt.Println(time.Since(start))
	} else {
		log.Fatalln("sort faild")
	}

}
