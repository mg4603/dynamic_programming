#include <iostream>
#include <vector>

#include <set>

std::vector<std::string> getAllSCS(
    std::string s1, std::string s2,
    int m, int n, std::vector<std::vector<int>> &lookup) {

    if(m == 0) {
        return {s2.substr(0, n)};
    }
    if(n == 0) {
        return {s1.substr(0, m)};
    }

    if(s1[m - 1] == s2[n - 1]) {
        std::vector<std::string> scs = 
                    getAllSCS(s1, s2, m - 1, n - 1, lookup);
        for(auto &it: scs) {
            it.push_back(s1[m - 1]);
        }
        return scs;
    } 

    if(lookup[m - 1][n] < lookup[m][n - 1]) {
        std::vector<std::string> scs = 
                getAllSCS(s1, s2, m - 1, n, lookup);
            
        for(auto &it: scs) {
            it.push_back(s1[m - 1]);
        }
        return scs;
    }
    
    if(lookup[m - 1][n] > lookup[m][n - 1]) {
        std::vector<std::string> scs =
                    getAllSCS(s1, s2, m, n - 1, lookup);
        
        for(auto &it: scs) {
            it.push_back(s2[n - 1]);
        }
        return scs;
    }

    std::vector<std::string> top = 
            getAllSCS(s1, s2, m - 1, n, lookup);
    
    for(auto &it: top) {
        it.push_back(s1[m - 1]);
    }

    std::vector<std::string> left =
            getAllSCS(s1, s2, m, n - 1, lookup);
    for(auto &it: left) {
        it.push_back(s2[n - 1]);
    }


    top.insert(top.end(), left.begin(), left.end());
    return top;
}

std::string getSCS(std::string s1, std::string s2,
                int m, int n, 
                std::vector<std::vector<int>> &lookup) {
    
    if(m == 0) {
        return s2.substr(0, n); 
    }
    if(n == 0) {
        return s1.substr(0, m);
    }

    if(s1[m - 1] == s2[n - 1]) {
        return getSCS(s1, s2, m - 1, n - 1, lookup) + s1[m - 1];
    } else {
        if(lookup[m - 1][n] < lookup[m][n - 1]) {
            return getSCS(s1, s2, m - 1, n, lookup) + s1[m - 1];
        }else {
            return getSCS(s1, s2, m, n - 1, lookup) + s2[n - 1];
        }
    }
}

int shortestCommonSupersequenceLength(
            std::string s1, std::string s2,
            int m, int n){

    if(m == 0 || n == 0){
        return m + n;
    }

    if(s1[m - 1] == s2[n - 1]) {
        return shortestCommonSupersequenceLength(
                        s1, s2, m - 1, n - 1) + 1;
    }
    return std::min(
        shortestCommonSupersequenceLength(s1, s2, m - 1, n) + 1,
        shortestCommonSupersequenceLength(s1, s2, m, n - 1) + 1);
}

int memoShortestCommonSupersequenceLength(
        std::string s1, std::string s2,
        int m, int n, 
        std::vector<std::vector<int>> &memo) {

        if(m == 0 || n == 0) {
            return m + n;
        }

        if(memo[m][n] != 0)return memo[m][n];

        if(s1[m - 1] == s2[n - 1]) {
            memo[m][n] = memoShortestCommonSupersequenceLength(s1, s2,
                            m - 1, n - 1, memo) + 1;
        }else {
            memo[m][n] = 
                std::min(
                  memoShortestCommonSupersequenceLength(
                    s1, s2, m - 1, n, memo) + 1,
                  memoShortestCommonSupersequenceLength(
                    s1, s2, m, n - 1, memo) + 1);
        }
        return memo[m][n];
}

int tableShortestCommonSupersequenceLength(
    std::string s1, std::string s2,
    int m, int n, std::vector<std::vector<int>> &table) {
    
    for(int i = 0; i <= m; i++) {
        table[i][0] = i;
    }

    for(int j = 0; j <= n; j++) {
        table[0][j] = j;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }else {
                table[i][j] = std::min(table[i - 1][j] + 1,
                                table[i][j - 1] + 1);
            }
        }
    }
    return table[m][n];
}

std::set<std::string> getAllSCS(std::string s1, std::string s2) {
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> lookup (m + 1, std::vector<int>(n + 1, 0));

    tableShortestCommonSupersequenceLength(s1, s2, m, n, lookup);
    std::vector<std::string> vec = getAllSCS(s1, s2, m, n, lookup);
    std::set<std::string> scs(vec.begin(), vec.end());
    return scs;
}

int main() {
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCABA";
    int m = s1.length(), n = s2.length();
    std::cout << "Len of shortest common supersequence: " 
            << shortestCommonSupersequenceLength(s1, s2, m, n) 
            << std::endl;
    
    std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, 0));
    std::cout << "Len of shortest common supersequence(memo): " 
            << memoShortestCommonSupersequenceLength(s1, s2, m, n, memo)
            << std::endl;

    std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));
    std::cout << "Len of shortest common supersequence(table): " 
            << tableShortestCommonSupersequenceLength(s1, s2, m, n, table)
            << std::endl;

    std::cout << "Shortest Common Supersequence: " 
            << getSCS(s1, s2, m, n, memo)
            << std::endl;

    
    std::cout << "All Shortest Common Supersequences: " << std::endl;

    for(auto &it: getAllSCS(s1, s2)) {
        std::cout << "\t\t" << it << std::endl;
    }
    return 0;
}