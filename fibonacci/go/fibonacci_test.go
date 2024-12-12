package fibonacci

import (
	"testing"
)

func Test_fib(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{
			name: "Base case #1: n = 0",
			n:    0,
			want: 0,
		},
		{
			name: "Base Case #2: n = 1",
			n:    1,
			want: 1,
		},
		{
			name: "Base Case #3: n = 2",
			n:    2,
			want: 1,
		},
		{
			name: "Simple Case #1: n = 6",
			n:    6,
			want: 8,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fib(tt.n); got != tt.want {
				t.Errorf("fib(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}

func Test_fibTopDown(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "fib(0)", n: 0, want: 0},
		{name: "fib(1)", n: 1, want: 1},
		{name: "fib(2)", n: 2, want: 1},
		{name: "fib(3)", n: 3, want: 2},
		{name: "fib(4)", n: 4, want: 3},
		{name: "fib(5)", n: 5, want: 5},
		{name: "fib(6)", n: 6, want: 8},
		{name: "fib(10)", n: 10, want: 55},
		{name: "fib(20)", n: 20, want: 6765},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fibTopDown(tt.n); got != tt.want {
				t.Errorf("fibTopDown(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}

func TestBottomUpForward(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "fib(0)", n: 0, want: 0},
		{name: "fib(1)", n: 1, want: 1},
		{name: "fib(2)", n: 2, want: 1},
		{name: "fib(3)", n: 3, want: 2},
		{name: "fib(4)", n: 4, want: 3},
		{name: "fib(5)", n: 5, want: 5},
		{name: "fib(6)", n: 6, want: 8},
		{name: "fib(10)", n: 10, want: 55},
		{name: "fib(20)", n: 20, want: 6765},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := BottomUpForward(tt.n); got != tt.want {
				t.Errorf("BottomUpForward(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}

func Test_fibBottomUpBackward(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "fib(0)", n: 0, want: 0},
		{name: "fib(1)", n: 1, want: 1},
		{name: "fib(2)", n: 2, want: 1},
		{name: "fib(3)", n: 3, want: 2},
		{name: "fib(4)", n: 4, want: 3},
		{name: "fib(5)", n: 5, want: 5},
		{name: "fib(6)", n: 6, want: 8},
		{name: "fib(10)", n: 10, want: 55},
		{name: "fib(20)", n: 20, want: 6765},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fibBottomUpBackward(tt.n); got != tt.want {
				t.Errorf("fibBottomUpBackward(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}
