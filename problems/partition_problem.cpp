// Partition Problem
//  The partition problem is to determine whether a given set can be 
//  partition into two subsets such that sum of elements in both subsets 
//  is the same

#include <vector>
#include <iostream>
#include <assert.h>
#include <map>

bool partitionProblem(int sum, int i, std::vector<int> &nums, 
            std::map<std::pair<int, int>, bool> &memo) {
    if(i == nums.size()) {
        if(sum == 0)return true;
        return false;
    }
    if(memo.count({i, std::abs(sum)})) 
            return memo[{i, std::abs(sum)}];

    memo[{i, std::abs(sum)}]  = partitionProblem(sum + nums[i], 
                                i + 1, nums, memo) || 
            partitionProblem(sum - nums[i], i + 1, nums, memo);
    return memo[{i, std::abs(sum)}];
}

int main() {
    std::vector<int> arr = {1, 5, 11, 5};
    bool res = true;
    std::map<std::pair<int, int>, bool> memo;
    assert(partitionProblem(0, 0, arr, memo) == res);

    arr = {1, 5, 3};
    res = false;
    memo.clear();
    assert(partitionProblem(0, 0, arr, memo) == res);
    return 0;
}