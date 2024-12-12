#include <vector>
#include <unordered_map>
#include <iostream>

bool canSum(int targetSum, std::vector<int> &nums) {
    if(targetSum == 0)return true;
    if(targetSum < 0)return false;

    for(int &num: nums) {
        if(canSum(targetSum - num, nums)) return true;
    }
    return false;
}

bool memo_canSum(int targetSum, std::vector<int> &nums,  
                std::unordered_map<int, bool> &memo) {
    if(targetSum == 0)return true;
    if(targetSum < 0)return false;
    if(memo.count(targetSum))return memo[targetSum];

    bool res = false;
    for(int &num: nums) {
        res |= memo_canSum(targetSum - num, nums, memo);
        if(res)break;
    }
    memo[targetSum] = res;
    return res;
}

bool tabCanSum(int targetSum, std::vector<int> &nums) {
    std::vector<bool> table(targetSum + 1, false);
    table[0] = true;

    for(int i = 0; i < targetSum + 1; i++) {
        if(table[i] == false)continue;
        for(auto &num: nums) {
            if(i + num < targetSum + 1) {
                table[i + num] = true;
            }
            if(i + num == targetSum)return true;
        }
    }
    return table[targetSum];
}

int main() {
    std::vector<int> nums = {5, 3, 4, 7};
    std::cout << "Can 7 be formed from [5, 3, 4, 7]: "
        << (canSum(7, nums) ? "True" : "False") << std::endl;
        
    std::vector<int> nums1 = {2, 4};
    std::unordered_map<int, bool> memo;
    std::cout << "Can 7 be formed from [2, 4]: " 
        << (memo_canSum(7, nums1, memo) ? "True" : "False") << std::endl;

    std::cout << "Can 1004 be formed from [5, 3, 4, 7]: "
        << (tabCanSum(1004, nums) ? "True" : "False") << std::endl;

    return 0;
}