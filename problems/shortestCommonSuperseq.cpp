// Shortest Common Super-sequence
//  Given two string str1 and str2, the task is to find the length 
//  of the shortest string that has both str1 and str2

#include <iostream>
#include <map>

int lcs(std::string a, std::string b, int i, int j, 
            std::map<std::pair<int, int>, int> &memo) {
    if(i == a.size() || j == b.size())return 0;
    if(memo.count({i, j}))return memo[{i, j}];
    if(a[i] == b[j]) {
        memo[{i, j}] = 1 + lcs(a, b, i + 1, j + 1, memo);
    }else {
        memo[{i, j}] = std::max(lcs(a, b, i + 1, j, memo), 
                        lcs(a, b, i, j + 1, memo));
    }
    return memo[{i, j}];
}

void printRes(std::string a, std::string b, int res) {
    std::cout << "Length of Shortest Common Super-sequence of: \n";
    std::cout << a << " and " << b << ": " << res << std::endl;
}

int main() {
    std::string str1 = "geek",  str2 = "eke";
    std::map<std::pair<int, int>, int> memo;
    printRes(str1, str2, 
            str1.length() + str2.length() - 
            lcs(str1, str2, 0, 0, memo)); // 5
    
    memo.clear();
    str1 = "AGGTAB", str2 = "GXTXAYB";
    printRes(str1, str2, 
            str1.length() + str2.length() - 
            lcs(str1, str2, 0, 0, memo)); // 9

    return 0;
}