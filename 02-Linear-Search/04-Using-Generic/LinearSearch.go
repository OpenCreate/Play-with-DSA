package main

func LinearSearch[T comparable](data []T, target T) int {
	for i := 0; i < len(data); i++ {
		if data[i] == target {
			return i
		}
	}
	return -1
}
