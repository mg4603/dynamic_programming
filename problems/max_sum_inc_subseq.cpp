// Maximum Sum Increasing Subsequence
//      Given an array of n positive integers. Write a program to 
//      find the sum of maximum sum subsequence of the given array 
//      such that the integers in the subsequence are sorted in 
//      increasing order.

#include <vector>
#include <iostream>
#include <climits>

int maxSumIncreasingSubseq(std::vector<int> &nums, int i, int n, int prev) {
    if(i == n)return 0;

    int exc = maxSumIncreasingSubseq(nums, i + 1, n, prev);
    int inc = 0;
    if(nums[i] > prev) {
        inc = nums[i] + maxSumIncreasingSubseq(nums, i + 1, n, nums[i]);
    }
    return std::max(inc, exc);
}

int dynamicMaxSumIncreasingSubseq(std::vector<int> &nums) {

    int n = nums.size();
    if(n == 0)return 0;

    std::vector<int> sums(n, 0);
    sums[0] = nums[0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && sums[i] < sums[j]) {
                sums[i] = sums[j];
            }
        }
        sums[i] += nums[i];
    }

    int res = 0;
    for(int &sum: sums) {
        res = std::max(res, sum);
    }

    return res;
}

void findMaxSumIncreasingSubseq(std::vector<int> &nums) {
    int n = nums.size();
    if(n == 0)return;

    std::vector<std::vector<int>> table(n);
    std::vector<int> sums(n, 0);

    sums[0] = nums[0];
    table[0].push_back(nums[0]);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && sums[i] < sums[j]) {
                sums[i] = sums[j];
                table[i] = table[j];
            }
        }
        sums[i] += nums[i];
        table[i].push_back(nums[i]);
    }

    int maxSum = 0;
    std::vector<int> res;
    for(int i = 0; i < n; i++) {
        if(sums[i] > maxSum) {
            maxSum = sums[i];
            res = table[i];
        }
    }

    for(int &num: res) {
        std::cout << num << ' ' ;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 
                             1, 9, 5, 13, 3, 11};
    
    int n = nums.size();
    std::cout << "The maximum sum of increasing subsequence: " 
                << maxSumIncreasingSubseq(nums, 0, n, INT_MIN)
                << std::endl;;

    std::cout << "The maximum sum of increasing subsequence(dynamic): " 
                << dynamicMaxSumIncreasingSubseq(nums)
                << std::endl;;
    
    std::cout << "Max sum increasing subsequence: " << std::endl;
    findMaxSumIncreasingSubseq(nums);
    return 0;
}