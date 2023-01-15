package main

import (
	"fmt"
	"log"
	"math/rand"
	"time"

	"golang.org/x/exp/constraints"
)

func InsertionSort[T constraints.Ordered](arr []T) {
	// arr(0,i] 有序 arr[i+1, n-1] 无序
	for i := 1; i < len(arr); i++ {
		//寻找合适的插入位置
		for j := i; j-1 >= 0 && arr[j-1] > arr[j]; j-- {
			arr[j], arr[j-1] = arr[j-1], arr[j] //swap
		}
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
	InsertionSort(d)
	if isSorted(d) {
		fmt.Println(time.Since(start))
	} else {
		log.Fatalln("sort faild")
	}
}
