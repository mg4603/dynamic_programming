// Optimal Game Strategy
//  Given a row of n coins of values V1....Vn, where n is even. We play a game
//  against an opponent by alternating turns. In each turn, a player selects 
//  either the first or last coin from the row, removes it permanently and 
//  and receives the value of the coin. Determine the maximum possible amount 
//  of money we can definitely win if we move first.

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

int ogs(std::vector<int> &values, int i, int j, 
        std::map<std::pair<int, int>, int> &memo) {

    if(i > j)return 0;
    if(i == j)return values[i];
    if(j == i + 1) return std::max(values[i], values[j]);
    if(memo.count({i, j}))return memo[{i, j}];

    memo[{i, j}] = std::max(values[i] + std::min(ogs(values, i + 2, j, memo), 
                                    ogs(values, i + 1, j - 1, memo)),
                    values[j] + std::min(ogs(values, i + 1, j - 1, memo),
                                    ogs(values, i, j - 2, memo)));
    return memo[{i, j}];
}

void printRes(std::vector<int> &values, int res) {
    std::cout << "Maximum Amount that can definitely be won \nwith amounts [";
    for(int i = 0; i < values.size(); i++) {
        if(i > 0)std::cout << ",";
        std::cout << values[i];
    }
    std::cout << "]: " << res << std::endl;
}
int main() {
    std::vector<int> values = {5, 3, 7, 10};
    std::map<std::pair<int, int>, int> memo;
    printRes(values, ogs(values, 0, values.size() - 1, memo));

    values = {8, 15, 3, 7};
    memo.clear();
    printRes(values, ogs(values, 0, values.size() - 1, memo));

    return 0;
}