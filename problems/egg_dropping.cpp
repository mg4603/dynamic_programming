// Egg dropping
//  * An egg that survives a fall can be used again. 
//  * A broken egg must be discarded. 
//  * The effect of a fall is the same for all eggs. 
//  * If an egg breaks when dropped, then it would break 
//      if dropped from a higher floor. 
// 
//  * If an egg survives a fall then it would survive a shorter fall. 
//  * It is not ruled out that the first-floor windows break eggs, nor
//      is it ruled out that the nth-floor does not cause an egg 
//      to break.

#include <iostream>
#include <climits>
#include <vector>

int eggDrop(int n, int k, 
        std::vector<std::vector<int>> &table) {
    if(n == 1 || n == 0)return n;
    if(k == 1)return n;
    if(table[n][k] != -1)return table[n][k];

    int res = INT_MAX;
    for(int i = 1; i <= n; i++) {
        res = std::min(res, 
                    std::max(eggDrop(n - i, k, table), 
                    eggDrop(i - 1, k - 1, table)));
    }
    table[n][k] = res + 1;
    return res + 1;
}

int main() {
    int n = 10;
    int k = 2;
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(k + 1, -1));
    std::cout << eggDrop(n, k, table) << std::endl;
}