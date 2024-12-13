package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMaximizeExpression(t *testing.T) {
	tests := []struct {
		name string
		A    []int64
		want int64
	}{
		{
			name: "Simple test #1",
			A:    []int64{3, 9, 10, 1, 30, 40},
			want: 46,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			assert.Equal(t, tt.want, MaximizeExpression(tt.A))
		})
	}
}
