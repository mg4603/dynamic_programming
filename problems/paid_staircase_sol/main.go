package paidstaircasesol

/*
Problem:

	Find cheapest path to the top of staircase if
	each step has a cost and you can climb 1...k
	stairs at any step
*/

func reverseSlice(s []int) []int {
	if len(s) == 0 {
		return s
	}
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func paidStaircase(cost []int, n int, k int) []int {
	var res []int
	if n == 0 {
		return res
	}
	dp := make([]int, n+1)
	prev := make([]int, n+1)

	dp[0] = 0
	prev[0] = -1

	for i := 1; i <= n; i++ {
		pos := i - 1
		min := dp[pos]

		for j := max(i-k, 0); j < i; j++ {
			if dp[j] < dp[pos] {
				min = dp[j]
				pos = j
			}
		}

		prev[i] = pos
		dp[i] = min + cost[i-1]
	}

	i := n
	for i > 0 {
		res = append(res, i-1)
		i = prev[i]
	}
	res = reverseSlice(res)
	return res

}
