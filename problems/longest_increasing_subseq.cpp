#include <vector>
#include <iostream>
#include <climits>

int lis(std::vector<int> nums, int i, int n, int prev) {
    if(i == n)return 0;

    int exc = lis(nums, i + 1, n, prev);

    int inc = 0;
    if(nums[i] > prev) {
        inc = lis(nums, i + 1, n, nums[i]) + 1;
    }
    return std::max(inc, exc);
}

int dynamic_lis(std::vector<int> &nums) {
    
    int n = nums.size();
    std::vector<int> table(n, 0);
    table[0] = 1;
    int res = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && table[j] > table[i]) {
                table[i] = table[j];
            }
        }
        table[i]++;
        res = std::max(res, table[i]);
    }
    return res;
}

int main() {

    std::vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 
                             1, 9, 5, 13, 3, 11, 7, 15};
    int n = nums.size();

    std::cout << "Length of longest increasing subsequence: " 
            << lis(nums, 0, n, INT_MIN) << std::endl;

    std::vector<int> memo(n, 0);
    std::cout << "Length of longest increasing subsequence(dynamic): " 
            << dynamic_lis(nums) << std::endl;
    return 0;
}