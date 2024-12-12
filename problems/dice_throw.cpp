// Dice Throw
//      Given n dice each with m faces, numbered from 1 to m, find the number 
//      of ways to get sum X. X is the summation of values on each face when 
//      all the dice are thrown.

#include <iostream>
#include <map>

int diceThrow(int m, int n, int X, 
            std::map<std::pair<int, int>, int> &memo) {
    if(X < 0)return 0;
    if(X == 0 && n == 0)return 1;
    if(memo.count({n, X}))return memo[{n, X}];
    
    int res = 0;
    for(int i = 1; i <= m; i++) {
        res += diceThrow(m, n - 1, X - i, memo);
    }
    memo[{n, X}] = res;
    return res;
}

int main() {
    std::map<std::pair<int, int>, int> memo;

    std::cout << diceThrow(4, 2, 1, memo) << std::endl; // 0

    memo.clear();
    std::cout << diceThrow(2, 2, 3, memo) << std::endl; // 2

    memo.clear();
    std::cout << diceThrow(6, 3, 8, memo) << std::endl; // 21

    memo.clear();
    std::cout << diceThrow(4, 2, 5, memo) << std::endl; // 4

    memo.clear();
    std::cout << diceThrow(4, 3, 5, memo) << std::endl; // 6
    return 0;
}