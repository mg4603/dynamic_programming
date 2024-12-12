// Minimum Perfect Squares to Add that Sum to Given Number
//      A number can always be represented as a sum of squares of other 
//      numbers. Note that 1 is a square and we can always break a 
//      number as (1*1 + 1*1 + 1*1 + …). Given a number n, find the 
//      minimum number of squares that sum to X.

#include <vector>
#include <assert.h>
#include <climits>
#include <iostream>
#include <unordered_map>

int fn(int n, std::unordered_map<int, int> &memo) {
    if(n < 0)return INT_MAX;
    if(n <= 3)return n;
    if(memo.count(n))return memo[n];
    
    int res = INT_MAX;
    for(int x = 1; x * x <= n; x++) {
        res = std::min(res, 1 + fn(n - x * x, memo));
    }
    memo[n] = res;
    return res;
}
int main() {
    std::unordered_map<int, int> memo;
    int n = 100, res = 1;
    assert(fn(n, memo) == res);

    n = 6, res = 3;
    memo.clear();
    assert(fn(n, memo) == res);
}