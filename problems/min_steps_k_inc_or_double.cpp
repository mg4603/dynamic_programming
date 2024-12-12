// Minimize steps to reach K from 0 by adding 1 or doubling at each step
#include <vector>
#include <iostream>
#include <climits>

int minStepsReachK(int k) {
    if(k <= 1)return k;
    std::vector<int> table(k + 1, INT_MAX);
    table[0] = 0;
    table[1] = 1;
    for(int i = 2; i < k + 1; i++) {
        if(i % 2 == 0) {
            table[i] = 1 + std::min(table[i - 1], table[i / 2]);
        }else {
            table[i] = 1 + table[i - 1];
        }
    }
    return table[k];
}

int main() {
    std::cout << "steps to 1: " << minStepsReachK(1) << std::endl;
    std::cout << "steps to 4: " << minStepsReachK(4) << std::endl;
    std::cout << "steps to 5: " << minStepsReachK(5) << std::endl;
    std::cout << "steps to 12: " << minStepsReachK(12) << std::endl;
    return 0;
}