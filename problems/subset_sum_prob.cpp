// Subset Sum Problem
//     Given a set of non-negative intergers and a value sum, check if 
//     there is a subset of the given set whose sum is equal to the vn
//     sum.

#include <iostream>
#include <vector>

bool isSubsetSum(int target, std::vector<int> &nums, 
                int i, std::vector<int> &memo) {
    if(i == nums.size() && target > 0 || target < 0)return false;
    if(target == 0)return true;
    if(memo[target] != -1)return memo[target];

    memo[target] = isSubsetSum(target, nums, i + 1, memo) || 
            isSubsetSum(target - nums[i], nums, i + 1, memo);
    return memo[target];
}

void printRes(int sum, std::vector<int> &st, bool res) {
    std::cout << "Is it possible to get " << sum 
            << " as the sum of a subset of \n[";
    for(int i = 0; i < st.size(); i++) {
        if(i > 0)std::cout << ",";
        std::cout << st[i];
    }
    std::cout << "]? " << (res ? "True" : "False") << std::endl;;
}

int main() {
    std::vector<int> set = {3, 34, 4, 12, 5, 2};

    int sum = 9;
    std::vector<int> memo(sum + 1, -1);
    printRes(sum, set, isSubsetSum(sum, set, 0, memo));
    
    sum = 60;
    memo.clear();
    memo.resize(sum + 1, -1);
    printRes(sum, set, isSubsetSum(sum, set, 0, memo));
    return 0;
}