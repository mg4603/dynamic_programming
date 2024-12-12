#include <iostream>
#include <vector>

int longest_palindromic_subseq(std::string s, int i, int j) {
    if(i > j)return 0;
    if(i == j)return 1;

    if(s[i] == s[j]) return 2 + longest_palindromic_subseq(s, i + 1, j - 1);
    return std::max(longest_palindromic_subseq(s, i + 1, j), longest_palindromic_subseq(s, i, j - 1));
}

int memo_longest_palindromic_subseq(std::string s, int i, 
                int j, std::vector<std::vector<int>> &memo) {
    if(i > j)return 0;
    if(i == j)return 1;
    if(memo[i][j] != 0)return memo[i][j];
    if(s[i] == s[j]){
        memo[i][j] = 2 + memo_longest_palindromic_subseq(s, i + 1, j - 1, memo);
    } else {
        memo[i][j] = std::max(memo_longest_palindromic_subseq(s, i + 1, j, memo), 
                memo_longest_palindromic_subseq(s, i, j - 1, memo));
    }
    return memo[i][j];
}

int main() {
    std::string s = "ABBDCACB";
    int n = s.length();
    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, 0));
    std::cout<< "Longst Palindromic Subseq len: " << 
        longest_palindromic_subseq(s, 0, n - 1) << std::endl;


    std::cout<< "Longst Palindromic Subseq len with memoization: " << 
        memo_longest_palindromic_subseq(s, 0, n - 1, memo) << std::endl;
        
    return 0;
}