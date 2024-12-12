# Grid Traveler

Find number of ways to get from start(1, 1) to end(n, m) of a n x m grid,  
when you can only travel to the right or down.

## Recursive
```
    gridTraveler(n, m): int
        if n = 1 and m = 1: return 1
        if n = 0 or m = 0: return 0
        return gridTraveler(n - 1, m) + gridTraveler(n, m - 1)
```
- Time Complexity:  
    $O(2^{n + m})$
- Space Complexity:  
    $O(n + m)$

## Memoization
```
    gridTraveler(n, m, memo): int
        if n = 1 and m = 1: return 1
        if n = 0 or m = 0: return 0

        if (n, m) in memo: return memo[(n, m)]
        if (m, n) in memo: return memo[(m, n)]
        memo[(n, m)] = gridTraveler(n - 1, m, memo) +
                                    gridTraveler(n, m - 1, memo)
        return memo[(n, m)]
```

- Time Complexity:  
    $O(n+m)$
- Space Complexity:  
    $O(n + m)$

## Tabulation
```
    gridTraveler(n, m): int
        table := initialize a 2d array of dimensions (n + 1) x (m + 1)
                and fill it with zeros
        table[1][1] = 1

        for i = 1 to n + 1:
            for j = 1 to m + 1:
                if i + 1 < n + 1:
                    table[i + 1][j] := table[i + 1][j] + table[i][j]
                if j + 1 < m + 1:
                    table[i][j + 1] := table[i][j + 1] + table[i][j]

        return table[i][j]
```
- Time Complexity:  
    $O(n \times m)$  
- Space Complexity:  
    $O(n \times m)$