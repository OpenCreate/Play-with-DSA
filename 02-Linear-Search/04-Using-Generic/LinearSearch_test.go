package main

import (
	"testing"
)

func TestLinearSearch(t *testing.T) {
	type args[E comparable] struct {
		data   []E
		target E
	}

	type cases[E comparable] struct {
		name string
		args args[E]
		want int
	}

	tests := []cases[int]{
		// TODO: Add test cases.
		{"empty", args[int]{data: []int{}, target: 1}, -1},
		{"find 3 ", args[int]{data: []int{1, 2, 3, -1}, target: -1}, 3},
		{"find 0", args[int]{data: []int{-1, 2, 3, -9}, target: -1}, 0},
		{"not find", args[int]{data: []int{-1, 2, 3, -9}, target: -10}, -1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := LinearSearch(tt.args.data, tt.args.target); got != tt.want {
				t.Errorf("LinearSearch() = %v, want %v", got, tt.want)
			}
		})
	}

	tests2 := []cases[string]{
		// TODO: Add test cases.
		{"find", args[string]{data: []string{"1", "2", "3"}, target: "1"}, 0},
		{"not find", args[string]{data: []string{"1", "2", "3"}, target: "11"}, -1},
	}

	for _, tt := range tests2 {
		t.Run(tt.name, func(t *testing.T) {
			if got := LinearSearch(tt.args.data, tt.args.target); got != tt.want {
				t.Errorf("LinearSearch() = %v, want %v", got, tt.want)
			}
		})
	}

	// 只能选择课比较的类型，slice 是不可以直接比较的
	type Student struct {
		Name string
		Age  int
	}
	s1 := []Student{
		{
			Name: "zhangsan",
			Age:  28,
		},
		{
			Name: "lisi",
			Age:  28,
		},
	}

	tests3 := []cases[Student]{
		// TODO: Add test cases.
		{"find", args[Student]{data: s1, target: Student{"lisi", 28}}, 1},
		{"not find", args[Student]{data: s1, target: Student{"wangwu", 28}}, -1},
	}
	for _, tt := range tests3 {
		t.Run(tt.name, func(t *testing.T) {
			if got := LinearSearch(tt.args.data, tt.args.target); got != tt.want {
				t.Errorf("LinearSearch() = %v, want %v", got, tt.want)
			}
		})
	}

}
