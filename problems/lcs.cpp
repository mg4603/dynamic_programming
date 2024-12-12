#include <iostream>
#include <vector>
#include <map>

int lcs(std::string x, std::string y, 
            std::map<std::pair<int, int>, int> &memo, 
            int i = 0, int j = 0) {

    if(i == x.length() || j == y.length())return 0;
    if(memo.count({i, j}))return memo[{i, j}];
    
    if(x[i] == y[j]) {
        memo[{i, j}] = 1 + lcs(x, y, memo, i + 1, j + 1);
    }else {
        memo[{i, j}] = std::max(lcs(x, y, memo, i + 1, j), 
                            lcs(x, y, memo, i, j + 1));
    }
    return memo[{i, j}];
}

void printRes(std::string x, std::string y, int res) {
    std::cout << "Longest Common Subsequence present in\n";
    std::cout << x << " and " << y << " is: " << res << std::endl;
}
int main() {
    std::string x = "ABC";
    std::string y = "ACD";
    std::map<std::pair<int, int>, int> memo;
    printRes(x, y, lcs(x, y, memo));

    x = "AGGTAB";
    y = "GXTXAYB";
    memo.clear();
    printRes(x, y, lcs(x, y, memo));

    x = "ABC";
    y = "CBA";
    memo.clear();
    printRes(x, y, lcs(x, y, memo));

    x = "XYZW";
    y = "XYWZ";
    memo.clear();
    printRes(x, y, lcs(x, y, memo));

    return 0;
}