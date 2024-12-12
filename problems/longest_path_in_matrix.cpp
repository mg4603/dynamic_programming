// Find the Longest Path in a matrix 
//      Given a n x n matrix where all numbers are distinct find longest 
//      path such that all cells along path are in increasing order with 
//      a difference of 1

#include <vector>
#include <iostream>
#include <map>

int dfs(std::vector<std::vector<int>> &mat, int n, int i, int j, 
            std::map<std::pair<int, int>, int> &memo) {
    if(i < 0 || j < 0 || i >= n || j >= n)return 0;
    if(memo.count({i, j}))return memo[{i, j}];
    int res = 0;
    if(i + 1 < n && mat[i + 1][j] == mat[i][j] + 1) {
        res = std::max(res, 1 + dfs(mat, n, i + 1, j, memo));
    }

    if(i - 1 >= 0 && mat[i - 1][j] == mat[i][j] + 1) {
        res = std::max(res, 1 + dfs(mat, n, i - 1, j, memo));
    }

    if(j + 1 < n && mat[i][j + 1] == mat[i][j] + 1) {
        res = std::max(res, 1 + dfs(mat, n, i, j + 1, memo));
    }

    if(j - 1 >= 0 && mat[i][j - 1] == mat[i][j] + 1) {
        res = std::max(res, 1 + dfs(mat, n, i, j - 1, memo));
    }
    memo[{i, j}] = res;
    return res;
}

int longestPath(std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    int res = 0;
    std::map<std::pair<int, int>, int> memo;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res = std::max(res, 1 + dfs(mat, n, i, j, memo));
        }
    }
    return res;
}

void printRes(std::vector<std::vector<int>> &mat, int res) {
    std::cout << "Longest Path in mat = \n\t[[";
    int n = mat.size();
    for(int i = 0; i < n; i++) {
        if(i > 0)std::cout << "\t [";
        for(int j = 0; j < n; j++) {
            if(j > 0)std::cout << ',';
            std::cout << mat[i][j];
        }
        if(i != n - 1)
        std::cout << "],\n";
    }
    std::cout << "]]: "<< std::endl;
    std::cout << res << std::endl;
}

int main() {
    std::vector<std::vector<int>> mat = 
                            {{1, 2, 9},
                             {5, 3, 8},
                             {4, 6, 7}}; //4

    printRes(mat, longestPath(mat));
    return 0;
}