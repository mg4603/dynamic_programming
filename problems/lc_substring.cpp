// Longest Common Substring
//      Given two strings ‘X’ and ‘Y’, find the length of the 
//      longest common substring. 

#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>

int lcs(std::string X, std::string y) {
    int n = X.size();
    int m = y.size();
    std::vector<std::vector<int>> table(n + 1, 
                            std::vector<int>(m + 1, 0));

    int res = 0;
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < m + 1; j++) {
            if(i == 0 || j == 0)continue;

            if(X[i - 1] == y[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                res = std::max(res, table[i][j]);
            }
        }
    }

    return res;
}

int main() {
    std::string X = "GeeksforGeeks", y = "GeeksQuiz" ;
    int res = 5;
    assert(lcs(X, y) == res);
    X = "abcdxyz", y = "xyzabcd";
    res = 4;
    assert(lcs(X, y) == res);

    X = "zxabcdezy", y = "yzabcdezx";
    res = 6;
    assert(lcs(X, y) == res);

    return 0;
}