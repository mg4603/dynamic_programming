package paintingfence2colors

/*
Problem

	There is a fence with n posts. Each post can be painted
	either green or blue. You have to paint all the posts
	such that no more than 2 adjacent fence posts have the
	same color.
	Return the total number of ways to paint the fence.


1. Objective function:
	f(i, j) is the number of ways to paint the first i
	posts, with the last post being painted j.

2. Base Case:
	F(1, 0) = 1
	F(1, 1) = 1
	F(2, 0) = 2
	F(2, 0) = 2

3. Transition Function
	F(i, j) = F(i - 1, 1 - j) + F(i - 2, 1 - j)

4. Answer
	F(n, 0) + F(n , 1)
*/

func NumWays(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 2
	}
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	dp[1][0] = 1
	dp[1][1] = 1
	dp[2][0] = 2
	dp[2][1] = 2

	for i := 3; i <= n; i++ {
		for j := 0; j < 2; j++ {
			dp[i][j] = dp[i-1][1-j] + dp[i-2][1-j]
		}
	}
	return dp[n][0] + dp[n][1]
}
