package mostprofitablepath

import (
	"reflect"
	"testing"
)

func Test_max(t *testing.T) {
	type args struct {
		a int
		b int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Case #1: (2,3)",
			args: args{a: 2, b: 3},
			want: 3,
		},
		{
			name: "Case #1: (6,5)",
			args: args{a: 6, b: 5},
			want: 6,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := max(tt.args.a, tt.args.b); got != tt.want {
				t.Errorf("max() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_MostProfit(t *testing.T) {
	tests := []struct {
		name string
		grid [][]int
		want int
	}{
		{
			name: "Base case #1: grid of size 1x1",
			grid: [][]int{{5}},
			want: 5,
		},
		{
			name: "Base case #2: grid of size 0x0",
			grid: [][]int{},
			want: 0,
		},
		{
			name: "Base case #3: grid of size 1x0",
			grid: [][]int{{}},
			want: 0,
		},
		{
			name: "Simple Case #1: grid of size 3x4",
			grid: [][]int{
				{0, 2, 2, 1},
				{3, 1, 1, 1},
				{4, 4, 2, 0},
			},
			want: 13,
		},
		{
			name: "Simple Case #2: grid of size 3x4",
			grid: [][]int{
				{0, 2, 2, 50},
				{3, 1, 1, 100},
				{4, 4, 2, 0},
			},
			want: 154,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := MostProfit(tt.grid); got != tt.want {
				t.Errorf("MostProfit(%v) = %v; want %v", tt.grid, got, tt.want)
			}
		})

	}
}

func Test_reverseSlice(t *testing.T) {
	tests := []struct {
		name  string
		input interface{}
		want  interface{}
	}{
		{
			name:  "Reverse Integers",
			input: []int{1, 2, 3, 4, 5},
			want:  []int{5, 4, 3, 2, 1},
		},
		{
			name:  "Reverse Strings",
			input: []string{"a", "b", "c", "d"},
			want:  []string{"d", "c", "b", "a"},
		},
		{
			name:  "Empty Slice",
			input: []int{},
			want:  []int{},
		},
		{
			name:  "Single Element",
			input: []string{"X"},
			want:  []string{"X"},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			inputValue := reflect.ValueOf(tt.input)
			copyValue := reflect.MakeSlice(inputValue.Type(), inputValue.Len(), inputValue.Cap())
			reflect.Copy(copyValue, inputValue)

			switch v := tt.input.(type) {
			case []int:
				reverseSlice(v)
			case []string:
				reverseSlice(v)
			}

			if !reflect.DeepEqual(inputValue.Interface(), tt.want) {
				t.Errorf("ReverseSlice(%v) = %v; want %v", copyValue.Interface(), inputValue.Interface(), tt.want)
			}
		})
	}
}

func Test_slicesEqual(t *testing.T) {
	type args struct {
		a []Pair
		b []Pair
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "Empty Slices",
			args: args{
				a: []Pair{},
				b: []Pair{},
			},
			want: true,
		},
		{
			name: "One Empty Slice",
			args: args{
				a: []Pair{},
				b: []Pair{{i: 1, j: 2}},
			},
			want: false,
		},
		{
			name: "Equal Single Element",
			args: args{
				a: []Pair{{i: 1, j: 2}},
				b: []Pair{{i: 1, j: 2}},
			},
			want: true,
		},
		{
			name: "Different Single Element",
			args: args{
				a: []Pair{{i: 1, j: 2}},
				b: []Pair{{i: 2, j: 2}},
			},
			want: false,
		},
		{
			name: "Mutliple Equal Elements",
			args: args{
				a: []Pair{{i: 1, j: 2},
					{i: 2, j: 3},
					{i: 3, j: 4}},
				b: []Pair{{i: 1, j: 2},
					{i: 2, j: 3},
					{i: 3, j: 4}},
			},
			want: true,
		},
		{
			name: "Mutliple Elements Not Equal",
			args: args{
				a: []Pair{{i: 1, j: 2},
					{i: 2, j: 3},
					{i: 5, j: 4}},
				b: []Pair{{i: 1, j: 2},
					{i: 2, j: 3},
					{i: 3, j: 4}},
			},
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := slicesEqual(tt.args.a, tt.args.b); got != tt.want {
				t.Errorf("slicesEqual() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestMostProfitablePath(t *testing.T) {
	tests := []struct {
		name     string
		costGrid [][]int
		want     []Pair
	}{
		{
			name:     "Base Case #1: 0x0",
			costGrid: [][]int{},
			want:     []Pair{},
		},
		{
			name:     "Base Case #2: 1x0",
			costGrid: [][]int{{}},
			want:     []Pair{},
		},
		{
			name:     "Base Case #1: 1x1",
			costGrid: [][]int{{5}},
			want:     []Pair{{i: 0, j: 0}},
		},
		{
			name: "Simple case #1: 3x4",
			costGrid: [][]int{
				{0, 2, 2, 1},
				{3, 1, 1, 1},
				{4, 4, 2, 0},
			},
			want: []Pair{
				{i: 0, j: 0}, {i: 1, j: 0}, {i: 2, j: 0},
				{i: 2, j: 1}, {i: 2, j: 2}, {i: 2, j: 3},
			},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := MostProfitablePath(tt.costGrid); !slicesEqual(got, tt.want) {
				t.Errorf("MostProfitablePath(%v) : %v; want %v",
					tt.costGrid, got, tt.want)
			}
		})
	}
}
