// Longest Increasing Subsequence
//      Given an array of size N, the task is to find the length of the  
//      longest increasing subsequence

#include <vector>
#include <iostream>

int lis(std::vector<int> &nums) {

    int res = 0;
    int n = nums.size();
    std::vector<int> table(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[j] > nums[i]) {
                table[j] = std::max(table[j], table[i] + 1);
            }
        }
        res = std::max(res, table[i]);
    }
    return res;
}

void printRes(std::vector<int> &nums, int res) {
    std::cout << "Longest Increasing subsequence in \n[";
    for(int i = 0; i < nums.size(); i++) {
        if(i > 0)std::cout << ',';
        std::cout << nums[i];
    }
    std::cout << "]: " << res << std::endl;
}
int main() {
    std::vector<int> nums = {3, 10, 2, 1, 20};
    printRes(nums, lis(nums)); //3 

    nums = {50, 3, 10, 7, 40, 80};
    printRes(nums, lis(nums)); // 4

    nums = {30, 20, 10};
    printRes(nums, lis(nums)); //1

    nums = {10, 20, 35, 80};
    printRes(nums, lis(nums)); //4

    return 0;
}