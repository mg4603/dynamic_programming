package paintingfence2colors

import "testing"

func TestNumWays(t *testing.T) {
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
			name: "Base case #2: n = 1",
			n:    1,
			want: 2,
		},
		{
			name: "Base case #3: n = 2",
			n:    2,
			want: 4,
		},
		{
			name: "Simple Test Case #1: n = 3",
			n:    3,
			want: 6,
		},
		{
			name: "Simple Test Case #2: n = 4",
			n:    4,
			want: 10,
		},
		{
			name: "Simple Test Case #3: n = 5",
			n:    5,
			want: 16,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := NumWays(tt.n); got != tt.want {
				t.Errorf("NumWays() = %v, want %v", got, tt.want)
			}
		})
	}
}
