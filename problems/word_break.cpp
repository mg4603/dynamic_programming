// Word Break Problem
//      Given an input string and a dictionary of words, find out if 
//      the input string can be segmented into a space-separated 
//      sequence of dictionary words.

#include <vector>
#include <iostream>
#include <map>

bool wordBreak(std::string str, 
                std::vector<std::string> &words,
                std::map<std::string, bool> &memo) {
    if(str == "")return true;

    for(std::string &word: words) {
        if(str.find(word) == 0) {
            memo[str] = wordBreak(str.substr(word.length()), 
                                    words, memo);
            return memo[str];
        }
    }
    memo[str] = false;
    return false;
}

int main() {
    std::vector<std::string> words = { "i", "like", "sam", 
                                        "sung", "samsung", 
                                        "mobile", "ice", 
                                        "cream", "icecream",
                                        "man", "go", "mango"};
    std::string str = "ilike";
    std::map<std::string, bool> memo;
    std::cout << wordBreak(str, words, memo) << std::endl;

    memo.clear();
    str = "ilikesamsun";
    std::cout << wordBreak(str, words, memo) << std::endl;

    return 0;
}