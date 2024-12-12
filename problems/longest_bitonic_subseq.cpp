#include <iostream>
#include <vector>
#include <list>

int longestBitonicSubsequence(std::vector<int> &nums) {
    
    int n = nums.size();
    std::vector<int> longestIncreasing(n, 0);
    std::vector<int> longestDecreasing(n, 0);

    int res = 0;
    longestIncreasing[0] = 1;
    longestDecreasing[n - 1] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && 
                longestIncreasing[i] < longestIncreasing[j]) {
                longestIncreasing[i] = longestIncreasing[j];
            }
        }
        longestIncreasing[i]++;
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(nums[i] > nums[j] && longestDecreasing[i] < longestDecreasing[j]) {
                longestDecreasing[i] = longestDecreasing[j];
            }
        }
        longestDecreasing[i]++;
    }

    for(int i = 0; i < n; i++) {
        res = std::max(longestDecreasing[i] + longestIncreasing[i] - 1, res);
    }
    return res;
}


void findLBS(std::vector<int> &nums) {

    int n = nums.size();

    if(n == 0)return;
    std::vector<std::list<int>> inc(n);
    std::vector<std::list<int>> dec(n);

    inc[0].push_back(nums[0]);
    dec[n - 1].push_front(nums[n - 1]);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && inc[i].size() < inc[j].size()) {
                inc[i] = inc[j];
            }
        }
        inc[i].push_back(nums[i]);
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(nums[j] < nums[i] && dec[i].size() < dec[j].size()) {
                dec[i] = dec[j];
            }
        }
        dec[i].push_front(nums[i]);
    }
    
    int peak = 0;
    for(int i = 0; i < n; i++) {
        if(dec[i].size() + inc[i].size() > inc[peak].size() + dec[peak].size()) {
            peak = i;
        }
    }
    
    std::cout << "Longest Bitonic Sequence: \n";

    for(int &num: inc[peak]) {
        std::cout << num << ' ';
    }

    dec[peak].pop_front();

    for(int &num: dec[peak]) {
        std::cout << num << ' ';
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {4, 2, 5, 9, 7, 6, 10, 3, 1};
    std::cout << "Length of longest Bitonic Sequence: " 
            << longestBitonicSubsequence(nums) << std::endl;
    
    findLBS(nums);
    return 0;
}