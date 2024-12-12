package uniquepaths

/*
Problem:
	How many unique ways exist to get to (m, n) from
	(0, 0) in a grid if at each cell you can either move
	one cell to the right or to the bottom.

1) Objective function
	F(i, j) gives the number of ways to get to cell (i, j)
2) Base Case:
	F(0, 0) => the number of ways to get to cell (0, 0):
		F(0, 0) = 1
3) Transition function:
	F(i, j) = F(i - 1, j) + F(i, j - 1)
*/

func uniquePaths(m int, n int) int {
	if m == 0 || n == 0 {
		return 0
	}

	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		dp[i][0] = 0
	}

	dp[0][0] = 1

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i-1 >= 0 {
				dp[i][j] += dp[i-1][j]
			}

			if j-1 >= 0 {
				dp[i][j] += dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}

type Pair struct {
	i, j int
}

type HashSet struct {
	elements map[Pair]struct{}
}

func NewHashSet() *HashSet {
	return &HashSet{elements: make(map[Pair]struct{})}
}

func (h *HashSet) Add(i, j int) {
	key := Pair{i: i, j: j}
	h.elements[key] = struct{}{}
}

func (h *HashSet) Remove(i, j int) {
	key := Pair{i: i, j: j}
	delete(h.elements, key)
}

func (h *HashSet) Contains(i, j int) bool {
	key := Pair{i: i, j: j}
	_, exists := h.elements[key]
	return exists
}

/*
Problem:

	How many ways are there to get to (m, n) from (0, 0)
	if you can move on step down or one step to the right
	at each cell except bad cells(cells you cannot move to)?

 1. Objective function:
    F(i, j) is the number of ways to get to (i, j) from 0

2. Base Case:
	F(0, 0) = 1

3. Transition function
	F(i, j) = 0, if (i, j) is a bad cell
			= F(i, j - 1) + F(i - 1, j) if (i, j) is not a bad cell
*/

func uniquePathsBadCells(m, n int, badCells []Pair) int {
	if m <= 0 || n <= 0 {
		return 0
	}
	set := NewHashSet()

	for _, pair := range badCells {
		set.Add(pair.i, pair.j)
	}

	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}

	dp[0][0] = 1

	for p := 0; p < m; p++ {
		for q := 0; q < n; q++ {
			if set.Contains(p, q) {
				dp[p][q] = 0
			} else {
				if p-1 >= 0 {
					dp[p][q] += dp[p-1][q]
				}
				if q-1 >= 0 {
					dp[p][q] += dp[p][q-1]
				}
			}
		}
	}
	return dp[m-1][n-1]
}
