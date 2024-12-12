#include <unordered_map>
#include <vector>
#include <iostream>

std::vector<int> howSum(int tgtSum, std::vector<int> &nums, 
                        int &flag) {
    if(tgtSum == 0) {
        flag = 0;
        return {};
    }
    if(tgtSum < 0) {
        flag = 1;
        return {};
    }

    for(int &num: nums) {
        std::vector<int> res = howSum(tgtSum - num, nums, flag);
        if(!flag) {
            res.push_back(num);
            return res;
        }
    }
    return {};
}

std::vector<int> memo_howSum(int tgtSum, std::vector<int> &nums, 
        int &flag, std::unordered_map<int, std::vector<int>> &memo) {
    
    if(tgtSum == 0) {
        flag = 0;
        return {};
    }
    if(tgtSum < 0) {
        flag = 1;
        return {};
    }
    if(memo.count(tgtSum)) {
        return memo[tgtSum];
    }

    for(int &num: nums) {
        std::vector<int> res = memo_howSum(tgtSum - num, nums, flag, memo);
        if(!flag) {
            res.push_back(num);
            memo[tgtSum] = res;
            return res;
        }
    }
    memo[tgtSum] = {};
    return {};
}

std::vector<int> tab_howSum(int targetSum, 
                        std::vector<int> &nums) {
    std::vector<bool> canSumTable(targetSum + 1, false);
    std::vector<std::vector<int>> table(targetSum + 1);

    canSumTable[0] = true;

    for(int i = 0; i < targetSum + 1; i++) {
        if(canSumTable[i]) {
            for(int &num: nums) {
                if(i + num <= targetSum && table[i + num].empty()) {
                    canSumTable[i + num] = true;
                    table[i + num] = table[i];
                    table[i + num].push_back(num);
                }
            }
        }
    }
    return table[targetSum];
}


void printRes(int tgtSum, std::vector<int> &nums, std::vector<int> &res) {
    std::cout << "Target Sum: " << tgtSum << " Numbers: [";
    for(int i = 0; i < nums.size(); i++) {
        if(i > 0) std::cout << ',';
        std::cout << nums[i];
    }
    std::cout << ']' << std::endl;

    if(res.size() == 0) {
        std::cout << "null" << std::endl;
        return;
    }
    std::cout << '[';
    for(int i = 0; i < res.size(); i++) {
        if(i > 0)std::cout << ',';
        std::cout << res[i];
    }
    std::cout << ']' << std::endl;
}

int main() {
    std::vector<int> nums = {2, 3};
    int flag = 0;
    std::vector<int> res;

    res = howSum(7, nums, flag);
    printRes(7, nums, res);

    flag = 0;
    res.clear();
    nums = {5, 3, 4, 7};
    res = howSum(7, nums, flag);
    printRes(7, nums, res);

    flag = 0;
    res.clear();
    nums = {2, 4};
    res = howSum(7, nums, flag);
    printRes(7, nums, res);

    flag = 0;
    res.clear();
    nums = {2, 3, 5};
    res = howSum(8, nums, flag);
    printRes(8, nums, res);

    flag = 0;
    res.clear();
    nums = {7, 14};
    std::unordered_map<int, std::vector<int>> memo;
    res = memo_howSum(300, nums, flag, memo);
    printRes(300, nums, res);

    res.clear();
    nums = {7, 14};
    res = tab_howSum(315, nums);
    printRes(315, nums, res);

    return 0;
}