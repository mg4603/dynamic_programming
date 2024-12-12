# Fibonacci

## Recursive
```
    fib(n): int
        if n <= 2:return 1
        return fib(n - 1) + fib(n - 2)
```
- Time Complexity  
    $O(2^{n+1} - 1) = 2^n$
- Space Complexity  
    $O(n)$

## Memoization
Store the results of computed sub-problems

```
    fib(n, memo): int
        if n in memo: return memo[n]
        if n <= 2: return 1

        memo[n] = fib(n - 1) + fib(n - 2)
        return memo[n]
```
- Time Complexity:  
    $O(2n - 3) = O(n)$

- Space Complexity:  
    $O(n) = O(n)$

## Tabulation 
```
    fib(n) : int
        table := initialize array of size n + 1
        table[1] = 1
        for i = 2 to n + 1:
            table[i] = table[i - 1] + table[i - 2]
        return table[n]
```
- Time Complexity:  
    $O(n)$
- Space Complexity:  
    $O(n)$