// Find Minimum Number of Coins to Make a given value (coin change)

//  Given an array of coins and a target number, return min number
//  of coins required to make the target. There are an infinite number
//  of each type of coin
#include <iostream>
#include <vector>
#include <climits>

int minCoins(std::vector<int> &coins, int val, std::vector<int> &memo) {
    if(memo[val] != -1)return memo[val];
    if(val < 0)return INT_MAX;
    if(val == 0)return 0;

    int numCoins = INT_MAX;
    for(int i = 0; i < coins.size(); i++) {
        int subNumCoins = minCoins(coins, val - coins[i], memo);

        if(subNumCoins != INT_MAX && subNumCoins + 1 < numCoins) {
            numCoins = subNumCoins + 1;
        }
    }
    memo[val] = numCoins;
    return numCoins;
}

void printRes(std::vector<int> &coins, int target, int res) {
    std::cout << "Min num coins to make " << target << " from [";
    
    for(int i = 0; i < coins.size(); i++) {
        if(i > 0) std::cout << ',';
        std::cout << coins[i];
    }
    std::cout << "]: \n";
    if(res == INT_MAX) {
        std::cout << -1;
    }else {
        std::cout << res;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> coins{25, 10, 5};
    std::vector<int> memo(501, -1);
    int res = minCoins(coins, 500, memo);
    printRes(coins, 500, res);
}