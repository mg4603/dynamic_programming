package coinchange

/*
Problem:

	Given an unlimited supply of coins of given
	denominations, find the unique ways to make change n

1. 	Objective function:
		F(i) is the unique ways to make
		change i

2.	Base Change:
		F(0) = 1

3.	Transition Function:

		F(n) = F(n - denominations[j]),

		if n - denominations[j] >= 0
		where,
		 j := 0 to m
		 m is the number of denominations

4.	Position of solution in cache:

		nth index

*/

func coinChange(denominations []int, n int) int {
	dp := make([]int, n+1)
	dp[0] = 1

	for _, denomination := range denominations {
		for i := 1; i <= n; i++ {
			if i >= denomination {
				dp[i] += dp[i-denomination]
			}
		}
	}
	return dp[n]
}

/*
Problem:

	Find the unique ways to make change n
	by using exactly c coins.

1.	Objective Function:
		F(i, c) is the unique ways to make
		change i with exactly c coins.

2.	Base Case:
		F(i, 0) = 0
		F(0, 0) = 1

		if i in denominations:
			F(i, 1) = 1
		else:
			F(i, 1) = 0

3. 	Transition function:

		for j in denominations:
			if i >= j:
				F(i, c) += F(i - j, c - 1)

*/

func exactlyCCoins(n int, c int, denominations []int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, c+1)
	}

	dp[0][0] = 1

	for _, denomination := range denominations {
		for i := 1; i <= n; i++ {
			for j := 1; j <= c; j++ {
				if i >= denomination {
					dp[i][j] += dp[i-denomination][j-1]
				}
			}
		}
	}
	return dp[n][c]
}

/*

No More than c coins:
F(0, j) = 1
*/

func noMoreThanCCoins(n int, c int, denominations []int) int {
	dp := make([][]int, n+1)

	for i := range dp {
		dp[i] = make([]int, c+1)
	}

	for j := 0; j <= c; j++ {
		dp[0][j] = 1
	}

	for _, denomination := range denominations {
		for i := 0; i <= n; i++ {
			for j := 1; j <= c; j++ {
				if i >= denomination {
					dp[i][j] += dp[i-denomination][j-1]
				}
			}
		}
	}
	return dp[n][c]
}

/*
Problem:
	Given an ulimited supply of coins of given denominations,
	find the unique ways to make change n by using
	an even number of coins

1. Objective function:
		F(i, x) is the unique ways to make change i
		with x = 0 if an odd # coins are used
		and x = 1 if an even # coins are used

2. Base Case:
		F(0, 0) = 0 // no way to make 0 from an odd number of coins
		F(0, 1) = 1 // 0 coins is an even number of coins and
					// you can make change of 0 using 0 coins
		F(1, 0) = 1
		F(1, 1) = 0

3.	Transition Function:

		F(i, x) = sum(F[i - denomination], 1 - x)) for each denomination

4. Solution at F(n, 1)
*/

func evenNumberCoins(n int, denominations []int) int {

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	dp[0][0] = 0
	dp[0][1] = 1

	for _, denomination := range denominations {
		for i := 1; i <= n; i++ {
			if i >= denomination {
				for j := 0; j < 2; j++ {
					dp[i][j] += dp[i-denomination][1-j]
				}
			}
		}
	}
	return dp[n][1]
}
