// Maximum Product Cutting
//  Given a rope of length n meters, cut the rope in different parts
//  of integer lengths in a ways that maximizes the product of lengths
//  of all parts. You must make atleast one cut.

#include <iostream>
#include <vector>
#include <algorithm>

long long maxProdCutting(int n) {
    if(n <= 2)return 1;

    std::vector<int> table(n + 1, 0);
    for(int i = 2; i < n + 1; i++) {
        for(int j = 1; j < i; j++) {
            table[i] = std::max({j * (i - j), 
                        j * table[i - j], table[i]});
        }
    }
    return table[n];
}
void printRes(int n, int res) {
    std::cout << "Max Obtainable Product for n = " << n << ": " << 
        res << std::endl;
}

int main() {
    int n = 2;
    printRes(n, maxProdCutting(n));
    n = 3;
    printRes(n, maxProdCutting(n));
    n = 4;
    printRes(n, maxProdCutting(n));
    n = 5;
    printRes(n, maxProdCutting(n));
    n = 10;
    printRes(n, maxProdCutting(n));

    return 0;
}