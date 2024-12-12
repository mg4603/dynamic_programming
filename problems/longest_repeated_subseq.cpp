#include <iostream>
#include <vector>

int longest_repeated_subseq(std::string s, int i, int j) {
    if(i == s.length() || j == s.length())return 0;

    if(s[i] == s[j] && i != j) {
        return 1 + longest_repeated_subseq(s, i + 1, j + 1);
    }
    return std::max(longest_repeated_subseq(s, i + 1, j), 
                longest_repeated_subseq(s, i , j + 1));
}

int memoLongestRepeatedSubseq(std::string s, int i, int j, 
                    std::vector<std::vector<int>> &memo) {
    
    if(i == s.length() || j == s.length())return 0;

    if(s[i] == s[j] && i != j) {
        memo[i][j] = 1 + memoLongestRepeatedSubseq(s, i + 1, j + 1, memo);
    }
    else {
        memo[i][j] = std::max(memoLongestRepeatedSubseq(s, i + 1, j, memo),
                memoLongestRepeatedSubseq(s, i, j + 1, memo));

    }
    return memo[i][j];
}

int main() {

    std::string s = "ATACTCGGA";
    std::cout << "The length of the longest repeated subsequence is: " 
            << longest_repeated_subseq(s, 0, 0) << std::endl;
    
    int n = s.length();
    std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));
    std::cout << "The length of the longest repeated subsequence(memo) is: " 
            << memoLongestRepeatedSubseq(s, 0, 0, memo) << std::endl;
    return 0;
}