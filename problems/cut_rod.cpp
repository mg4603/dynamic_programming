// Cutting a Rod
//  Given a rod of length n and an array of prices of all pieces of 
//  size smaller than or equal to n. Determine max value obtainable 
//  by cutting up the rod and selling the pieces.

#include <vector>
#include <iostream>

int rodCut(int n, std::vector<int> &prices, std::vector<int> &memo) {
    if(n == 0)return 0;
    if(memo[n] != -1)return memo[n];
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = std::max(res, prices[i - 1] + 
                    rodCut(n - i, prices, memo));
    }
    memo[n] = res;
    return res;
}

int main() {
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    std::vector<int> memo(prices.size() + 1, -1);
    std::cout << rodCut(prices.size(), prices, memo) << std::endl;

    prices = {3, 5, 8, 9, 10, 17, 17, 20};
    memo.clear();
    memo.resize(prices.size() + 1, -1);
    std::cout << rodCut(prices.size(), prices, memo) << std::endl;
    return 0;
}