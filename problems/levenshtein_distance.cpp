#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int levenshteinDistance(std::string s1, std::string s2, 
        int n, int m) {

    if(n == 0 || m == 0){
        return std::max(n, m);
    }

    if(s1[n - 1] == s2[m - 1]) {
        return levenshteinDistance(s1, s2, n - 1, m - 1);
    }else {
        return 1 + std::min({levenshteinDistance(s1, s2, n - 1, m),
                        levenshteinDistance(s1, s2, n, m - 1),
                        levenshteinDistance(s1, s2, n - 1, m - 1)});
    }
}

int dynamicLevenshteinDistance(std::string s1, std::string s2, 
        int n, int m, std::vector<std::vector<int>> &memo) {

    if(n == 0 || m == 0){
        return std::max(n, m);
    }
    if(memo[n][m] != INT_MAX)return memo[n][m];

    if(s1[n - 1] == s2[m - 1]) {
        memo[n][m] = dynamicLevenshteinDistance(s1, s2, n - 1, m - 1, memo);
    }else {
        memo[n][m] =  1 + std::min({
                dynamicLevenshteinDistance(s1, s2, n - 1, m, memo),
                dynamicLevenshteinDistance(s1, s2, n, m - 1, memo),
                dynamicLevenshteinDistance(s1, s2, n - 1, m - 1, memo)});
    }
    return memo[n][m];
}

int main() {
    std::string s1 = "kitten";
    std::string s2 = "sitting";
    int n = s1.size();
    int m = s2.size();
    std::cout << "The Levenshtein Distance is: " 
            << levenshteinDistance(s1, s2, n, m) << std::endl;

    std::vector<std::vector<int>> memo(n + 1, 
                    std::vector<int>(m + 1, INT_MAX));
    std::cout << "The Levenshtein Distance(dynamic) is: " 
            << dynamicLevenshteinDistance(s1, s2, n, m, memo)
            << std::endl;;
    return 0;
}