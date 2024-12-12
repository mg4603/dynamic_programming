package uniquepaths

import (
	"testing"
)

func Test_uniquePaths(t *testing.T) {
	type args struct {
		m int
		n int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Base case #1",
			args: args{
				m: 1,
				n: 1,
			},
			want: 1,
		},
		{
			name: "Simple case #1",
			args: args{
				m: 2,
				n: 2,
			},
			want: 2,
		},
		{
			name: "Simple case #2",
			args: args{
				m: 1,
				n: 2,
			},
			want: 1,
		},
		{
			name: "Simple case #3",
			args: args{
				m: 2,
				n: 1,
			},
			want: 1,
		},
		{
			name: "Simple case #4",
			args: args{
				m: 2,
				n: 3,
			},
			want: 3,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := uniquePaths(tt.args.m, tt.args.n); got != tt.want {
				t.Errorf("uniquePaths() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestHashset_Add(t *testing.T) {
	tests := []struct {
		name        string
		intputPairs []Pair
		checkPairs  []Pair
		expected    []bool
	}{
		{
			name: "Add Unique Pairs",
			intputPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
				{i: 2, j: 3},
			},
			expected: []bool{true, true, false},
		},
		{
			name: "Add Duplicate Pairs",
			intputPairs: []Pair{
				{i: 1, j: 2},
				{i: 1, j: 2},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
			},
			expected: []bool{true},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			set := NewHashSet()

			for _, pair := range tt.intputPairs {
				set.Add(pair.i, pair.j)
			}

			for idx, pair := range tt.checkPairs {
				if got := set.Contains(pair.i, pair.j); got != tt.expected[idx] {
					t.Errorf("Contains (%v) : %v; want %v", pair, got, tt.expected[idx])
				}
			}
		})
	}

}

func TestHashSet_Remove(t *testing.T) {
	tests := []struct {
		name        string
		initial     []Pair
		removePairs []Pair
		checkPairs  []Pair
		expected    []bool
	}{
		{
			name: "Remove existing pairs",
			initial: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
			},
			removePairs: []Pair{
				{i: 1, j: 2},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
			},
			expected: []bool{false, true},
		},
		{
			name: "Remove non-existing pairs",
			initial: []Pair{
				{i: 1, j: 2},
			},
			removePairs: []Pair{
				{i: 3, j: 4},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
			},
			expected: []bool{true, false},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			set := NewHashSet()

			for _, pair := range tt.initial {
				set.Add(pair.i, pair.j)
			}

			for _, pair := range tt.removePairs {
				set.Remove(pair.i, pair.j)
			}

			for idx, pair := range tt.checkPairs {

				if got := set.Contains(pair.i, pair.j); got != tt.expected[idx] {
					t.Errorf("Contains (%v): %v; want %v", pair, got, tt.expected[idx])
				}
			}
		})
	}
}

func TestHashset_Contains(t *testing.T) {
	tests := []struct {
		name       string
		initial    []Pair
		checkPairs []Pair
		expected   []bool
	}{
		{
			name: "Check in populated set",
			initial: []Pair{
				{i: 1, j: 2},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
			},
			expected: []bool{true, false},
		},
		{
			name:    "Check in empty set",
			initial: []Pair{},
			checkPairs: []Pair{
				{i: 1, j: 2},
			},
			expected: []bool{false},
		},
	}

	for _, tt := range tests {
		set := NewHashSet()

		for _, pair := range tt.initial {
			set.Add(pair.i, pair.j)
		}

		for idx, pair := range tt.checkPairs {
			if got := set.Contains(pair.i, pair.j); got != tt.expected[idx] {
				t.Errorf("Contains (%v): %v; want %v", pair, got, tt.expected[idx])
			}
		}

	}
}

func Test_uniquePathsBadCells(t *testing.T) {
	type args struct {
		m        int
		n        int
		badCells []Pair
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Base Case #1 : (0, 0)",
			args: args{
				m: 0,
				n: 0,
				badCells: []Pair{
					{i: 1, j: 1},
				},
			},
			want: 0,
		},
		{
			name: "Base Case #2 : (5, 0)",
			args: args{
				m: 5,
				n: 0,
				badCells: []Pair{
					{i: 1, j: 1},
				},
			},
			want: 0,
		},
		{
			name: "Base Case #3 : (0,6)",
			args: args{
				m: 0,
				n: 6,
				badCells: []Pair{
					{i: 1, j: 1},
				},
			},
			want: 0,
		},
		{
			name: "Base Case #4 : (1,1)",
			args: args{
				m: 1,
				n: 1,
				badCells: []Pair{
					{i: 1, j: 1},
				},
			},
			want: 1,
		},
		{
			name: "Simple Case #1 : (2,2)",
			args: args{
				m: 2,
				n: 2,
				badCells: []Pair{
					{i: 1, j: 0},
				},
			},
			want: 1,
		},
		{
			name: "Simple Case #2 : (2,2)",
			args: args{
				m: 2,
				n: 2,
				badCells: []Pair{
					{i: 1, j: 1},
				},
			},
			want: 0,
		},
		{
			name: "Simple Case #3 : (2,3)",
			args: args{
				m: 2,
				n: 3,
				badCells: []Pair{
					{i: 1, j: 1},
				},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := uniquePathsBadCells(tt.args.m, tt.args.n, tt.args.badCells); got != tt.want {
				t.Errorf("uniquePathsBadCells() = %v, want %v", got, tt.want)
			}
		})
	}
}
