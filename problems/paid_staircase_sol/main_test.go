package paidstaircasesol

import (
	"reflect"
	"testing"
)

func Test_reverseSlice(t *testing.T) {
	type args struct {
		s []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "Base case #1",
			args: args{
				s: []int{1, 2, 3, 4},
			},
			want: []int{4, 3, 2, 1},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reverseSlice(tt.args.s); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("reverseSlice() = %v, want %v", got, tt.want)
			}
		})
	}
}

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
			name: "Simple Test #1",
			args: args{
				a: 2,
				b: 3,
			},
			want: 3,
		},
		{
			name: "Simple Test #2",
			args: args{
				a: 3,
				b: 2,
			},
			want: 3,
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

func Test_paidStaircase(t *testing.T) {
	type args struct {
		cost []int
		n    int
		k    int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "base case #1",
			args: args{
				cost: []int{1, 2},
				n:    2,
				k:    2,
			},
			want: []int{1},
		},
		{
			name: "simple case #1",
			args: args{
				cost: []int{2, 3, 4, 6, 1, 1, 5, 3},
				n:    8,
				k:    2,
			},
			want: []int{0, 2, 4, 5, 7},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := paidStaircase(tt.args.cost, tt.args.n, tt.args.k); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("paidStaircase() = %v, want %v", got, tt.want)
			}
		})
	}
}
