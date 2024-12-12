# BestSum

Given a non-negative integer targetSum and an array of non-negative integers  
numbers, find the shortest combination in numbers that sums to targetSum  
without replacement.

## Recursive

```
    bestSum(tgtSum, [numbers]): => [int]
        if tgtSum = 0: return []
        if tgtSum < 0: return null

        shortestCombination := null

        for number in numbers:
            combination := bestSum(tgtSum - number, [numbers])
            if combination != null:
                - append number to combination
                - if shortestCombination = null or shortestCombination  
                         is longer than combination:
                     shortest := combination
        
        return shortest
```
- Time Complexity:  
    $O(n^m * m)$  
    where,  
    - n is the number of elements in numbers  
    - m is targetSum
- Space Complexity:  
    $O(m^2)$

## Memoization
```
    bestSum(targetSum, [numbers], memo): ==> [int]
        if targetSum = 0:return []
        if targetSum < 0: return null
        if targetSum in memo: return memo[targetSum]

        shortestCombination := null

        for number in numbers:
            combination := bestSum(targetSum - number, [numbers], memo)
            if combination != null:
                - append number to combination
                - if shortestCombination = null or shortestCombination 
                        is longer than combination:
                     shortestCombination := combination
        
        memo[targetSum] := shortestCombination
        return shortestCombination
``` 
- Time Complexity:  
    $O(n * m * m)$  
    - Copying combination to shortestCombination takes $O(m)$ time
    where,  
    - n is the number of elements in numbers  
    - m is targetSum
- Space Complexity:  
    $O(m^2)$

## Tabulation
```
    bestSum(targetSum, [numbers]) : => [int]
        table := initialize a 2D array of size targetSum + 1 with empty 
                integer arrays
        canSumTable := initialize an array of size targetSum + 1 with 
                false values
        
        canSumTable[0] := true

        for i := 0 to targetSum + 1:
            if canSumTable[i] = true:
                for number in numbers:
                    if i + number <= targetSum: 
                        canSumTable[i + number] := true

                        if table[i + number] is empty or 
                                table[i + number].length > table[i].length:
                             - table[i + number] := table[i]
                             - append number to table[i + number]

        return table[targetSum]
```
- Time Complexity:  
    $O(n * m * m)$  
    where,  
    - n is the number of elements in numbers  
    - m is targetSum
- Space Complexity:  
    $O(m^2)$