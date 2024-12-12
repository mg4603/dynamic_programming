// Count Number of Ways to Cover a Distance
//  Given a distance 'dist' count total number of ways to cover distance 
//  with 1, 2 and 3 steps

#include <iostream>
#include <vector>

int countWays(int targetDistance, std::vector<int> &memo) {
    if(targetDistance < 0)return 0;
    if(targetDistance == 0)return 1;
    if(memo[targetDistance] != -1)return memo[targetDistance];

    int res = 0;
    for(int i = 1; i <= 3; i++) {
        res += countWays(targetDistance - i, memo);
    }

    memo[targetDistance] = res;
    return res;
}

void printRes(int targetDistance, int res) {
    std::cout << "# ways to cover " << targetDistance <<  
        ": " << res << std::endl;
    return;
}
int main() {
    int n = 3;
    std::vector<int> memo(n + 1, -1);
    printRes(n, countWays(n, memo));

    n = 4;
    memo.clear();
    memo.resize(n + 1, -1);
    printRes(n, countWays(n, memo));

    n = 20;
    memo.clear();
    memo.resize(n + 1, -1);
    printRes(n, countWays(n, memo));
    return 0;
}