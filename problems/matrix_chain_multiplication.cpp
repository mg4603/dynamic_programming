#include <vector>
#include <iostream>
#include <climits>

int matrixChainMultiplication(std::vector<int> &dims, int i, int j) {
    if(j <= i + 1)return 0;

    int min_cost = INT_MAX;
    for(int k = i + 1; k < j; k++) {
        int cost = matrixChainMultiplication(dims, i, k);
        cost += matrixChainMultiplication(dims, k, j);
        cost += dims[i] * dims[k] * dims[j];
        min_cost = std::min(min_cost, cost);
    }
    return min_cost;
}

int dynamicMatrixChainMultiplication(std::vector<int> &dims, 
                int i, int j, std::vector<std::vector<int>> &table) {

    if(j <= i + 1)return 0;
    if(table[i][j] != 0)return table[i][j];

    int min_cost = INT_MAX;

    for(int k = i + 1; k < j; k++) {
        int cost = dynamicMatrixChainMultiplication(dims, i, k, table);
        cost += dynamicMatrixChainMultiplication(dims, k, j, table);
        cost += (dims[i] * dims[k] * dims[j]);
        min_cost = std::min(cost, min_cost);
    }
    
    table[i][j] = min_cost;
    return table[i][j];
}

int main() {
    std::vector<int> dims = {10, 30, 5, 60};
    int n = dims.size();

    std::cout << "The minimum cost is: " 
            << matrixChainMultiplication(dims, 0, n - 1)
            << std::endl;;
    
    std::vector<std::vector<int>> table(n + 1, 
                                std::vector<int>(n + 1, 0));
    std::cout << "The minimum cost(dynamic) is: " 
            << dynamicMatrixChainMultiplication(dims, 0, n - 1, table)
            << std::endl;;
    return 0;
}