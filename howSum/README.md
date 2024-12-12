# HowSum

Given a non-negative integer targetSum and an array of non-negative integers  
numbers, return possible combination so numbers taken with replacement that  
result in targetSum.

## Recursive

```
    howSum(targetSum, [numbers]): -> [int]
        if targetSum = 0: return []
        if targetSum < 0: return null

        for number in numbers:
            res := howSum(target - number, numbers)
            if res != null:
                add number to res
                return res
        return null
```
- Time Complexity  
    $O(n^m*m)$
- Space Complexity:  
    $O(m)$
## Memoization

```
    howSum(targetSum, [numbers], memo): ->[int]
        if targetSum = 0: return []
        if targetSum < 0: return null
        if targetSum in memo: return memo[targetSum]

        for number in numbers:
            res := howSum(target - number, numbers, memo)
            if res != null:
                add number to res
                break
                
        memo[targetSum] = res
        return res
```
- Time Complexity  
    $O(n*m^2)$  
    - copying res takes m time
- Space Complexity:  
    $O(m^2)$  
    - worst case is if res is all 1s

## Tabulation

```
    howSum(targetSum, [numbers]) : => [int]
        table := initialize a 2D array of of size targetSum  + 1 of  
                size empty integer arrays
        canSumTable := initialize an array of size targetSum  + 1 
                with False
        
        canSumTable[0] = True

        for i = 1 to targetSum + 1;
            if canSumTable[i] = True:
                if i + num <= targetSum:
                    - canSumTable[i + num] = True
                    - table[i + num] := table[i]
                    - append num to table[i + num]
        return table[i + num]
```

- Time Complexity  
    $O(n*m^2)$  
    - copying res takes m time
- Space Complexity:  
    $O(m^2)$

