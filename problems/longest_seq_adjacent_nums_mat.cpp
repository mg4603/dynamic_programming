#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findLongestSeq(
        std::vector<std::vector<int>> &mat, int i, int j) {
    
    int n = mat.size();
    std::vector<int> longestSeq = {};
    if(i >= n || j >= n || i < 0 || j < 0)return longestSeq;

    if(i > 0 && mat[i - 1][j] == mat[i][j] + 1) {
        std::vector<int> seq = findLongestSeq(mat, i - 1, j);
        if(seq.size() > longestSeq.size())longestSeq = seq;
    }

    if(i + 1 < n && mat[i + 1][j] == mat[i][j] + 1) {
        std::vector<int> seq = findLongestSeq(mat, i + 1, j);
        if(seq.size() > longestSeq.size())longestSeq = seq;
    }

    if(j > 0 && mat[i][j - 1] == mat[i][j] + 1) {
        std::vector<int> seq = findLongestSeq(mat, i, j - 1);
        if(seq.size() > longestSeq.size())longestSeq = seq;
    }

    if(j + 1 < n && mat[i][j + 1] == mat[i][j] + 1) {
        std::vector<int> seq = findLongestSeq(mat, i, j + 1);
        if(seq.size() > longestSeq.size())longestSeq = seq;
    }

    longestSeq.push_back(mat[i][j]);
    return longestSeq;
}

std::vector<int> findLongestSeq(
                std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    std::vector<int> longestSeq = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::vector<int> seq = findLongestSeq(mat, i, j);
            if(longestSeq.size() < seq.size()) {
                longestSeq = seq;
            }
        }
    }
    std::reverse(longestSeq.begin(), longestSeq.end());
    return longestSeq;
}

std::vector<int> dynamicFindLongestSeq(
    std::vector<std::vector<int>> &mat, int i, int j,
    std::vector<std::vector<std::vector<int>>> &memo){
    
    int n = mat.size();
    std::vector<int> longestSeq;
    if(i < 0 || j < 0 || i >= n || j >= n)return longestSeq;
    if(memo[i][j].size() > 0)return memo[i][j];
    
    if(i > 0 && mat[i - 1][j] == mat[i][j] + 1) {
        std::vector<int> seq = dynamicFindLongestSeq(
                                    mat, i - 1, j, memo);
        if(longestSeq.size() < seq.size()) {
            longestSeq = seq;
        }
    }

    if(i + 1 < n && mat[i + 1][j] == mat[i][j] + 1) {
        std::vector<int> seq = dynamicFindLongestSeq(
                                    mat, i + 1, j, memo);
        if(longestSeq.size() < seq.size()) {
            longestSeq = seq;
        }
    }

    if(j > 0 && mat[i][j - 1] == mat[i][j] + 1) {
        std::vector<int> seq = dynamicFindLongestSeq(
                                    mat, i, j - 1, memo);
        if(longestSeq.size() < seq.size()) {
            longestSeq = seq;
        }
    }

    if(j + 1 < n && mat[i][j + 1] == mat[i][j] + 1) {
        std::vector<int> seq = dynamicFindLongestSeq(
                                    mat, i, j + 1, memo);
        if(longestSeq.size() < seq.size()) {
            longestSeq = seq;
        }
    }
    
    longestSeq.push_back(mat[i][j]);
    memo[i][j] = longestSeq;
    return memo[i][j];
}


std::vector<int> dynamicFindLongestSeq(
        std::vector<std::vector<int>> &mat) {
    
    int n = mat.size();
    std::vector<std::vector<std::vector<int>>> memo(n, std::vector<std::vector<int>>(n));
    std::vector<int> longestSeq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::vector<int> seq = dynamicFindLongestSeq(mat, i, j, memo);
            if(longestSeq.size() < seq.size()) {
                longestSeq = seq;
            }
        }
    }
    std::reverse(longestSeq.begin(), longestSeq.end());
    return longestSeq;
}
template <typename T>
void printVector(std::vector<T> &vec) {
    for(T it: vec) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> mat =
    {
        { 10, 13, 14, 21, 23 },
        { 11, 9, 22, 2, 3 },
        { 12, 8, 1, 5, 4 },
        { 15, 24, 7, 6, 20 },
        { 16, 17, 18, 19, 25 }
    };
    std::cout << "LongestSeq: " << std::endl;;
    std::vector<int> res = findLongestSeq(mat);
    printVector(res);

    std::cout << "Longest Seq(dynamic): " << std::endl;;
    res = dynamicFindLongestSeq(mat);
    printVector(res);
    return 0;
}