package coinchange

import (
	"testing"
)

func Test_coinChange(t *testing.T) {
	tests := []struct {
		name          string
		denominations []int
		n             int
		want          int
	}{

		{
			name:          "Basic case",
			denominations: []int{1, 2, 5},
			n:             5,
			want:          4, // {5}, {2,2,1}, {2,1,1,1}, {1,1,1,1,1}
		},
		{
			name:          "Single denomination",
			denominations: []int{1},
			n:             3,
			want:          1, // {1,1,1}
		},
		{
			name:          "No solution possible",
			denominations: []int{2, 4},
			n:             3,
			want:          0,
		},
		{
			name:          "Larger value",
			denominations: []int{1, 2, 5},
			n:             10,
			want:          10,
		},
		{
			name:          "Edge case zero",
			denominations: []int{1, 2, 5},
			n:             0,
			want:          1, // No coins needed
		},
		{
			name:          "Simple case",
			denominations: []int{1, 3, 5, 10},
			n:             3,
			want:          2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := coinChange(tt.denominations, tt.n); got != tt.want {
				t.Errorf("coinChange(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}

func Test_exactlyCCoins(t *testing.T) {
	tests := []struct {
		name          string
		n             int
		c             int
		denominations []int
		expected      int
	}{

		{
			name:          "Basic case, exact solution exists",
			n:             5,
			c:             2,
			denominations: []int{1, 2, 3, 4},
			expected:      2,
		},
		{
			name:          "Impossible case with insufficient coins",
			n:             5,
			c:             1,
			denominations: []int{1, 2, 3},
			expected:      0,
		},
		{
			name:          "Case with larger denominations",
			n:             10,
			c:             3,
			denominations: []int{2, 5, 3, 6},
			expected:      2,
		},
		{
			name:          "Edge case: No denominations",
			n:             7,
			c:             2,
			denominations: []int{},
			expected:      0,
		},
		{
			name:          "Edge case: Zero target amount",
			n:             0,
			c:             0,
			denominations: []int{1, 2, 3},
			expected:      1,
		},
		{
			name:          "Exact coins equal target",
			n:             6,
			c:             2,
			denominations: []int{3, 6},
			expected:      1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := exactlyCCoins(tt.n, tt.c, tt.denominations); got != tt.expected {
				t.Errorf("exactlyCCoins(%v, %v, %v) = %v, want %v", tt.n, tt.c, tt.denominations, got, tt.expected)
			}
		})
	}
}

func Test_noMoreThanCCoins(t *testing.T) {

	tests := []struct {
		name          string
		n             int
		c             int
		denominations []int
		want          int
	}{
		{
			name:          "Base Case #1: n = 0, any c",
			n:             0,
			c:             5,
			denominations: []int{1, 3, 5, 7},
			want:          1,
		},
		{
			name:          "Base Case #2: n = 0, c = 0",
			n:             0,
			c:             0,
			denominations: []int{1, 3, 5, 7},
			want:          1,
		},
		{
			name:          "Simple Case #1: n = 5, c = 2",
			n:             5,
			c:             2,
			denominations: []int{1, 2, 3},
			want:          1, //{2, 3},
		}, {
			name:          "Simple Case #2: n = 5, c = 3",
			n:             5,
			c:             3,
			denominations: []int{1, 2, 3},
			want:          3, //{1, 2, 2}, {2, 3}, {1,1,3}
		},
		{
			name:          "Simple Case #3: n = 3, c = 1",
			n:             3,
			c:             1,
			denominations: []int{1, 2, 3},
			want:          1,
		},
		{
			name:          "Simple Case #4: n = 6, c = 2",
			n:             6,
			c:             1,
			denominations: []int{1, 2, 3},
			want:          0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := noMoreThanCCoins(tt.n, tt.c, tt.denominations); got != tt.want {
				t.Errorf("noMoreThanCCoins(%v, %v, %v) = %v, want %v", tt.n, tt.c, tt.denominations, got, tt.want)
			}
		})
	}
}

func Test_evenNumberCoins(t *testing.T) {
	tests := []struct {
		name          string
		n             int
		denominations []int
		want          int
	}{
		{
			name:          "Base Case#1: n = 0",
			n:             0,
			denominations: []int{1, 2, 3, 5},
			want:          1,
		},
		{
			name:          "Simple Case#1: n = 5",
			n:             5,
			denominations: []int{1, 2, 3},
			want:          2, // Valid combinations: {2+3} and {1+1+1+3}.
		},
		{
			name:          "Simple Case#2: n = 6",
			n:             6,
			denominations: []int{1, 2, 3},
			want:          4,
		},
		{
			name:          "Simple Case#3: n = 6",
			n:             6,
			denominations: []int{1, 3, 5, 10},
			want:          4,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := evenNumberCoins(tt.n, tt.denominations); got != tt.want {
				t.Errorf("evenNumberCoins(%v, %v) = %v, want %v", tt.n, tt.denominations, got, tt.want)
			}
		})
	}
}
