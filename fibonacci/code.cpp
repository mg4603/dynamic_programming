#include <iostream>

#include <unordered_map>
#include <vector>

long long recursive_fib(int n) {
    if(n <= 2)return 1;
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

long long memo_fib(int n,  
            std::unordered_map<int, long long> &memo) {
    if(memo.count(n))return memo[n];
    if(n <= 2)return 1;
    memo[n] = memo_fib(n - 1, memo) + memo_fib(n - 2, memo);
    return memo[n];
}

long long tabFib(int n) {
    std::vector<long long> table(n + 1, 0);
    table[1] = 1;
    for(int i = 2; i < n + 1; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}
int main() {
    std::unordered_map<int, long long> mp;
    std::cout << "Fibonacci: \n";
    std::cout << "fib(5): " << recursive_fib(5) << std::endl;
    std::cout << "fib(50): " << memo_fib(50, mp) << std::endl;
    std::cout << "fib(51): " << tabFib(51) << std::endl;
    return 0;
}