package main

import "testing"

func TestLinearSearch(t *testing.T) {
	type args struct {
		data   []int
		target int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
		{"empty", args{data: []int{}, target: 1}, -1},
		{"find 3 ", args{data: []int{1, 2, 3, -1}, target: -1}, 3},
		{"find 0", args{data: []int{-1, 2, 3, -9}, target: -1}, 0},
		{"not find", args{data: []int{-1, 2, 3, -9}, target: -10}, -1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := LinearSearch(tt.args.data, tt.args.target); got != tt.want {
				t.Errorf("LinearSearch() = %v, want %v", got, tt.want)
			}
		})
	}
}
