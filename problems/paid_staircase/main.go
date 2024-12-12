package paidstaircase

/*

	Problem:
		what is the minimum cost to get to the nth
		step if you can climb either one or two
		steps on each step

	Objective function:
		f(i) is the minimum cost to get to the ith stair

	base case:
		f(0) = 0
		f(1) = cost[1]

	recurrence relation:
		f(n) = min{f(n - 1), f(n - 2)} + cost[n]

	order of computation:
		bottom-up

	location of solution:
		at the nth index of cache

	time complexity: O(n);
	space complexity: O(n)
*/

func paidStaircase(n int, cost []int) int {
	if n == 0 {
		return 0
	}

	dp := make([]int, n+1)
	dp[0] = 0
	dp[1] = cost[1]

	for i := 2; i <= n; i++ {
		dp[i] = min(dp[i-1], dp[i-2]) + cost[i-1]
	}
	return dp[n]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
