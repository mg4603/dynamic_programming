#include <iostream>
#include <vector>
#include <assert.h>
/*
    Problem:
    Find sum of first natural numbers:

    Objective function:
    f(i) is the sum of first i elements

    Recurrence relation:
    f(n) = f(n - 1) + 1
*/

int sumNNums(int n);

void test(std::string name, int n, int res) {
    std::cout << "Test " << name << ":" << std::endl;
    assert(sumNNums(n) == res);
    std::cout << "Passed" << std::endl;
}
int main() {
    test("Edge case #1", 0, 0);
    test("Edge case #2", 1, 1);
    test("Simple Test #1", 5, 15);

    return 0;
}

int sumNNums(int n) {
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + i;
    }
    return dp[n];
}

