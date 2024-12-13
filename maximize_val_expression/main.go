package main

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

/*
Problem:
	Find the max value of expression A[s] - A[p] + A[q] - A[r]
	where s > p > q > r.

	1) Objective function:

		maximize A[s] - A[p] + A[q] - A[r]
		where  s > p > q > r

	2) Base Case
		n < 4 => 0

		dp1[0] = - A[0] // only one element is available at index 0

		dp2[1] = dp1[0] + A[1] // best value of -A[r] upto index 0
								// added to value at index q


		dp3[2] = dp2[1] - A[2]  // best value of A[q] - A[r] upto index 1
								// added to negative of value at index p


		dp4[3] = dp3[2] + A[3]  // best value of - A[p] + A[q] - A[r]
								// upto index 2 added to value at index s

	3) Transition function

		dp1[i] = max(dp1[i-1], -A[i])
		dp2[i] = max(dp2[i-1], dp1[i-1] + A[i])
		dp3[i] = max(dp3[i-1], dp2[i-1] - A[i])
		dp4[i] = max(dp4[i-1], dp3[i-1] + A[i])


	4) Location of solution
		dp4[n-1]


*/

func MaximizeExpression(A []int64) int64 {
	n := len(A)

	if n < 4 {
		return 0
	}

	dp1 := make([]int64, n)
	dp2 := make([]int64, n)
	dp3 := make([]int64, n)
	dp4 := make([]int64, n)

	dp1[0] = -A[0]
	dp2[1] = dp1[0] + A[1]
	dp3[2] = dp2[1] - A[2]
	dp4[3] = dp3[2] + A[3]
	for i := 1; i < n; i++ {
		dp1[i] = max(dp1[i-1], -A[i])
		if i > 1 {
			dp2[i] = max(dp2[i-1], dp1[i-1]+A[i])
		}
		if i > 2 {
			dp3[i] = max(dp3[i-1], dp2[i-1]-A[i])
		}
		if i > 3 {
			dp4[i] = max(dp4[i-1], dp3[i-1]+A[i])
		}
	}

	return dp4[n-1]
}

func main() {

}
