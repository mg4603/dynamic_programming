// 0/1 knapsack problem
//  Given N items each with some weight and profit associated with it and 
//  a bag with capacity W. The task is to put the items into the bag such 
//  that the sum of profits associated with them is the maximum possible.

#include <iostream>
#include <vector>
#include <map>

int knapsack(int W, std::vector<int> &weights, 
             std::vector<int> &profits, int i, 
             std::map<std::pair<int, int>, int> &memo) {
    if(i == weights.size() || W == 0)return 0;
    if(memo.count({i, W}))return memo[{i, W}];
    
    if(weights[i] > W) {
        memo[{i, W}] = knapsack(W, weights, profits, i + 1, memo);
    }else {
        memo[{i, W}] = std::max(
                knapsack(W - weights[i], weights, 
                        profits, i + 1, memo) + profits[i], 
                knapsack(W, weights, profits, i + 1, memo));
    }
    return memo[{i, W}];
}

void printRes(int W, std::vector<int> &profit, std::vector<int> & weight, int res) {
    std::cout << "Max profit that can be obtained with a knapsack of size " 
            << W << "\nitems [weight: profit] :" << std::endl;
    for(int i = 0; i < profit.size(); i++) {
        std::cout << '[' << weight[i] << ":" << profit[i] << "]" << std::endl;
    }
    std::cout << res << std::endl;
    
}

int main() {
    int W = 4;
    std::vector<int> profit = {1, 2, 3};
    std::vector<int> weight = {4, 5, 1}; //3;
    std::map<std::pair<int, int>, int> memo;
    printRes(W, profit, weight, knapsack(W, weight, profit, 0, memo));

    weight = {2, 3, 4, 5};
    profit = {3, 4, 5, 6};
    W = 5;
    memo.clear();
    printRes(W, profit, weight, knapsack(W, weight, profit, 0, memo));

    return 0;
}