# CountConstruct

Given a string targetString and an array of words wordBank, return the number  
of ways to concatenate elements of wordBank to form targetString. 

## Recursive 

```
    countConstruct(targetString, [wordBank]): => bool
        if targetString is empty: return 1

        countWays = 0
        for word in wordBank:
            if word is prefix of targetString:
                suffix := targetString after removing word from  
                            the start
                countSuffixWays := countConstruct(suffix, 
                                wordBank)

                countWays := countWays + countSuffixWays
        return countWays
```

### Time Complexity  
- $O(n^m\times m)$  
- where,  
    - n is the number of words in wordBank
    - m is the length of targetString
- In the worst case, where elements of wordBank are of length 1, the height  
    of tree is m.
- Cost of finding suffix is m
### Space Complexity:  
- $O(m^2)$
- Stack size is m and cost of storing suffix in each call is m

## Memoization

```
    countConstruct(targetString, [wordBank], memo) : => int
        if targetString is empty: return 1
        if targetString in memo: return memo[targetString]

        countWays := 0

        for word in wordBank:
            if word is prefix of targetString:
                suffix := targetString after removing word from  
                        the start
                countSuffixWays := countConstruct(targetString, 
                            [wordBank], memo)
                countWays := countWays + countSuffixWays
                
        memo[targetString] = countWays
        return countWays
```

### Time Complexity  
- $O(n\times m\times m)$  
- where,  
    - n is the number of words in wordBank
    - m is the length of targetString
### Space Complexity:  
- $O(m^3)$
- Stack size is m, cost of storing suffix in each call is m, memo size is m.

## Tabulation

```
    countConstruct(targetString, [wordBank]) : -> int
        table := initialize array of size targetString.length + 1  
                with 0s
        
        table[0] := 1

        for i = 0 to targetString.length + 1:
            if table[i] > 0:
                for word in wordBank: 
                    pos := targetString.find(word, i)

                    if pos = i:
                        table[i + word.length] += 1
        return table[targetString.length]
```

### Time Complexity  
- $O(n\times m\times m)$  
- where,  
    - n is the number of words in wordBank
    - m is the length of targetString
### Space Complexity:  
- $O(m)$