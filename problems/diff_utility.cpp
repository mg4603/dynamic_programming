#include <iostream>
#include <vector>

void diff(std::string s1, std::string s2, 
        int n, int m, std::vector<std::vector<int>> &lookup) {
    
    if(m > 0 && n > 0 && s1[n - 1] == s2[m - 1]) {
        diff(s1, s2, n - 1, m - 1, lookup);
        std::cout << " " << s1[n - 1];
    }else if(m > 0 && (n == 0 || lookup[n][m - 1] >= lookup[n - 1][m])) {
        diff(s1, s2, n, m - 1, lookup);
        std::cout << " +" << s2[m - 1];
    }else if(n > 0 && (m == 0 || lookup[n - 1][m] > lookup[n][m - 1])) {
        diff(s1, s2, n - 1, m, lookup);
        std::cout << " -" << s1[n - 1];
    }
}

std::vector<std::vector<int>> findLCS(std::string s1, std::string s2) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }else {
                table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table;
}

int main() {
    std::string s1 = "ABCDFGHJQZ";
    std::string s2 = "ABCDEFGIJKRXYZ";

    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<int>> lookup = findLCS(s1, s2);
    diff(s1, s2, n, m, lookup);
    std::cout << std::endl;
    return 0;
}