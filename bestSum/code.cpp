#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> bestSum(int targetSum, 
                std::vector<int> &numbers, int &flag) {
    if(targetSum == 0) {
        flag = 1;
        return {};
    }
    if(targetSum < 0) {
        flag = 0;
        return {};
    }

    std::vector<int> shortestCombination;

    for(int num: numbers) {
        std::vector<int> combination = bestSum(targetSum - num, 
                                numbers, flag);
        if(flag) {
            combination.push_back(num);
            if(shortestCombination.empty() || 
                    shortestCombination.size() > combination.size()) {
                shortestCombination = combination;
            }
        }
    }
    return shortestCombination;
}

std::vector<int> memoBestSum(int targetSum, std::vector<int> &nums, 
                    std::unordered_map<int, std::vector<int>> &memo,
                    int &flag) {
    
    if(targetSum == 0) {
        flag = 1;
        return {};
    }
    if(targetSum < 0) {
        flag = 0;
        return {};
    }
    if(memo.count(targetSum))return memo[targetSum];

    std::vector<int> shortestCombination;
    for(int &num: nums) {
        std::vector<int> combination = memoBestSum(targetSum - num, nums, 
                                        memo, flag);
        if(flag) {
            combination.push_back(num);
            if(shortestCombination.empty() ||  
                    shortestCombination.size() > combination.size()) {
                shortestCombination = combination;
            }
        }
        flag = 1;
    }
    memo[targetSum] = shortestCombination;
    return shortestCombination;
}

std::vector<int> tabBestSum(int targetSum, std::vector<int> &numbers) {
    std::vector<bool> canSumTable(targetSum + 1);
    std::vector<std::vector<int>> table(targetSum + 1);
    canSumTable[0] = true;

    for(int i = 0; i < targetSum + 1; i++) {
        if(canSumTable[i] == true) {
            for(int &num: numbers) {
                if(i + num <= targetSum) {
                    canSumTable[i + num] = true;
                    if(table[i + num].empty() ||  
                            table[i + num].size() > table[i].size()) {
                        table[i + num] = table[i];
                        table[i + num].push_back(num);
                    }
                }
            }
        }
    }
    return table[targetSum];
}
void printRes(int targetSum, std::vector<int> &nums, 
                std::vector<int> &res) {
    
    std::cout << "Target: " << targetSum << " Numbers: [";
    for(int i = 0; i < nums.size(); i++) {
        if(i > 0)std::cout << ',';
        std::cout << nums[i];
    }
    if(res.empty()) {
        std::cout << "]\nResult: null\n" << std::endl;
        return;
    }
    std::cout << "]\nResult: [";
    for(int i = 0; i < res.size(); i++) {
        if(i > 0)std::cout << ',';
        std::cout << res[i];
    }
    std::cout << "]\n" << std::endl;
    return;
}

int main() {

    int targetSum = 7;
    std::vector<int> nums = {5, 3, 4, 7};
    int flag = 1;
    std::vector<int> res = bestSum(targetSum, nums, flag);
    printRes(targetSum, nums, res);

    flag = 1;
    targetSum = 8;
    nums = {2,3,5};
    res = bestSum(targetSum, nums, flag);
    printRes(targetSum, nums, res);

    flag = 1;
    nums = {1, 4, 5};
    targetSum = 8;
    res = bestSum(targetSum, nums,flag);
    printRes(targetSum, nums, res);


    targetSum = 100;
    flag = 1;
    nums = {1, 2, 5, 25};
    std::unordered_map<int, std::vector<int>> memo;
    res = memoBestSum(targetSum, nums, memo, flag);
    printRes(targetSum, nums, res);

    nums = {1, 4, 5};
    targetSum = 8;
    res = tabBestSum(targetSum, nums);
    printRes(targetSum, nums, res);

    return 0;
}