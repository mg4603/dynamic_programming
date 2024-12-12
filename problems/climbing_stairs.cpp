#include <iostream>
#include <vector>
#include <assert.h>

/*
    Problem:
    Find the distinct number of ways to reach a certain 
    stair, if on any stair, we can climb take either
    one or two steps.

    Objective fn:
    f(i) is the distinct number of ways to get to the ith stair

    Recurrence Relation:
    f(i) = f(i - 1) + f(i - 2)

    Base case:
        f(0) = 1 => do nothing
        f(1) = 1
*/

int f(int n, std::vector<int> &memo);

int f(int n) {
    if(n == 0 || n == 1)return 1;
    int a = 1;
    int b = 1;

    for(int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

void test(std::string testName, int n, int res) {
    std::cout << testName << ": ";
    assert(f(n) == res);
    std::cout << "Passed" << std::endl;;
}


int f(int n, std::vector<int> &memo) {
    if(n == 0 || n == 1)return 1;
    if(memo[n] != 0)return memo[n];
    memo[n] = f(n - 1, memo) + f(n - 2, memo);
    return memo[n];
}

int main() {
    test("Base case #1", 1, 1);
    test("Base case #2", 0, 1);

    test("Simple Test #1", 2, 2);

    return 0;
}