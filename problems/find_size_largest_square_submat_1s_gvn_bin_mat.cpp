#include <iostream>
#include <vector>

int findLargestSquareSubmatrix(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> table(n + 1, 
                        std::vector<int>(m + 1, 0));

    int res = 0;
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++) {
            if(matrix[i - 1][j - 1]) {
                table[i][j] = std::min(table[i - 1][j], 
                            std::min(table[i - 1][j - 1], 
                                table[i][j - 1])) + 1;
                res = std::max(table[i][j], res);
            }
        }
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> mat =
    {
        { 0, 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1 }
    };
 
    std:: cout << "The size of the largest square submatrix of 1's is: " 
        << findLargestSquareSubmatrix(mat)
        << std::endl;;
    return 0;
}