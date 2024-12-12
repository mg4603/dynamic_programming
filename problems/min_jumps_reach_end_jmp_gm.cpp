// Minimum number of jumps to reach end (Jump Game)
//      Given an array arr[] where each element represents the max number 
//      of steps that can be made forward from that index. The task is to 
//      find the minimum number of jumps to reach the end of the array 
//      starting from index 0.

#include <vector>
#include <iostream>
#include <assert.h>
#include <climits>

int fn(std::vector<int> &arr, int i, std::vector<int> &memo) {
    if(i >= arr.size() - 1)return 0;
    if(arr[i] == 0)return INT_MAX;
    if(memo[i] != -1)return memo[i];

    int res = INT_MAX;
    int n = arr[i] + i;
    for(int j = i + 1; j < arr.size() && j <= n; j++) {
        int jumps = fn(arr, j, memo);
        if(jumps != INT_MAX && jumps + 1 < res) {
            res = jumps + 1;
        }
    }
    memo[i] = res;
    return res;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int res = 3;
    std::vector<int> memo(arr.size(), -1);
    assert(fn(arr, 0, memo) == res);

    arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    res = 10;
    memo.clear();
    memo.resize(arr.size(), - 1);
    assert(fn(arr, 0, memo) == res);

    return 0;
}