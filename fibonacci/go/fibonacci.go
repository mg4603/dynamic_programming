package fibonacci

// recursive solution
func fib(n int) int {
	if n == 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	return fib(n-1) + fib(n-2)
}

// Top-down solution: (memoization + recursion)
func fibTopDown(n int) int {
	memo := make(map[int]int)
	return fibTopDownHelper(n, memo)
}

func fibTopDownHelper(n int, memo map[int]int) int {
	if n == 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	if res, ok := memo[n]; ok {
		return res
	}

	memo[n] = fibTopDownHelper(n-1, memo) + fibTopDownHelper(n-2, memo)
	return memo[n]
}

// Bottom-up (forward dynamic programming)
func BottomUpForward(n int) int {
	if n == 0 {
		return 0
	}

	if n <= 2 {
		return 1
	}

	dp := make([]int, n+1)
	dp[0] = 0
	dp[1] = 1
	for i := 2; i <= n; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return dp[n]
}

// Bottom-up (backward dynamic programming)
// 	dp[i] is used to solve the next sub-problem
// 	dp[i + 1] += dp[i]
// 	dp[i + 2] += dp[i]

func fibBottomUpBackward(n int) int {
	if n == 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	dp := make([]int, n+2)
	dp[0] = 0
	dp[1] = 1
	for i := 1; i < n; i++ {
		dp[i+1] += dp[i]
		dp[i+2] += dp[i]
	}
	return dp[n]
}
