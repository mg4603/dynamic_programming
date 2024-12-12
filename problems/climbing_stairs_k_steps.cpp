#include <iostream>
#include <vector>
#include <assert.h>


/*
    Problem:
        find distinct ways to get to nth step if
        you can take 1...k steps at each step.

    Objective function:
        f(i) is the distinct number  of ways to get
        to ith step
    
    Base case:
        f(0) = 1
        f(1) = 1
    
    Recurrence relation:
        f(n) = f(n - 1) + ... + f(n - k)
    Order of operation:
        botton-up
    
    location of solution:
        nth element of 0 indexed cache
*/

int f(int n, int k);

void test(std::string testCase, int n, int k, int res) {
    std::cout << testCase << ": " << std::endl;
    assert(f(n, k) == res /*Failed*/);
    std::cout << "Passed" << std::endl;
}

int main() {
    test("Base case #1 (n = 0, k = 2)", 0, 2, 1);
    test("Base case #2 (n = 1, k = 2)", 1, 2, 1);
    test("Simple Case #1 (n = 3, k = 2)", 3, 2, 3);
    test("Simple Case #2 (n = 3, k = 3)", 3, 3, 4);
    test("Simple Case #3 (n = 5, k = 3)", 5, 3, 13);
    return 0;
}

int f(int n, int k) {
    std::vector<int> dp(k);
    dp[k - 2] = 1;
    dp[k - 1] = 1;

    for(int i = 2; i <= n; i++) {
        int temp = dp[0];
        for(int j = 1; j < k; j++) {
            temp += dp[j];
            dp[j - 1] = dp[j];
        }
        dp[k - 1] = temp;
    }
    return dp[k - 1];
}