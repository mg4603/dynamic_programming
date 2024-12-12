// Calculate the size of the largest plus of 1’s in a binary matrix
//      Given a square matrix of 0's and 1's, calculate the size of the 
//      largest plus formed by 1's.

#include <vector>
#include <assert.h>
#include <iostream>
#include <algorithm>

int fn(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    std::vector<std::vector<int>> left, right, top, bottom;
    left = grid, right = grid, top = grid, bottom = grid;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > 0)top[i][j] = top[i - 1][j] + grid[i][j];
            if(i + 1 < n)bottom[n - i - 2][j] = bottom[n - i - 1][j] + grid[n - i - 2][j];
            if(j > 0)left[i][j] = left[i][j - 1] + grid[i][j];
            if(j + 1 < n)right[i][n - j - 2] = right[i][n - j - 1] + grid[i][n - j - 2];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res = std::max(res, std::min({left[i][j], 
                        right[i][j], top[i][j], bottom[i][j]}));
        }
    }
    return (res - 1) * 4 + 1;;
}
int main() {
    std::vector<std::vector<int>> grid = 
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
    int res = 17;
    assert(fn(grid) == res);
}