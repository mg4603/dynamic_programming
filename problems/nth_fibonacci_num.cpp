// Nth Fibonacci Number
//  Given a number n, print n-th Fibonacci Number. 

#include <vector>
#include <assert.h>

int fibonacci(int n) {
    std::vector<int> table(n + 1, 0);
    table[1] = 1;
    for(int i = 2; i < n + 1; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}
int main() {
    int n = 1, res = 1;
    assert(fibonacci(n) == res);

    n = 9, res = 34;
    assert(fibonacci(n) == res);

    n = 10, res = 55;
    assert(fibonacci(n) == res);

    return 0;
}