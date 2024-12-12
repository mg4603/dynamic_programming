#include <iostream>
#include <vector>

// Cn = summation(Ci * Cn-i-1) from i = 1 to n - 1

long long catlanNum(int n) {
    if(n <= 1) return 1;
    std::vector<int> memo(n + 1, 0);
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2; i < n + 1; i++) {
        for(int j = 0; j < i; j++) {
            memo[i] += memo[j] * memo[i - j - 1];
        }
    }
    return memo[n];
}

int main() {
    std::cout << "5th Catlan Number: " << catlanNum(5) << std::endl;
    return 0;
}