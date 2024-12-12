#include <iostream>
#include <vector>
#include <unordered_map>

bool canConstruct(std::string targetString,  
                    std::vector<std::string> &wordBank) {

    if(targetString == "")return true;

    for(auto &word: wordBank) {
        if(targetString.find(word) == 0) {
            std::string suffix = targetString.substr(word.length());
            if(canConstruct(suffix, wordBank))return true;
        }
    }
    return false;
}

bool memoCanConstruct(std::string targetString,  
                std::vector<std::string> &wordBank,  
                std::unordered_map<std::string, bool> &memo) {
    
    if(targetString == "")return true;
    if(memo.count(targetString))return memo[targetString];

    bool canConstruct = false;

    for(auto &word: wordBank) {
        if(targetString.find(word) == 0) {
            std::string suffix = targetString.substr(word.length());
            canConstruct = memoCanConstruct(suffix, wordBank, memo);
            if(canConstruct)break;
        }
    }
    memo[targetString] = canConstruct;
    return canConstruct;
}

bool tabCanConstruct(std::string targetString, 
                std::vector<std::string> &wordBank) {
        std::vector<bool> table(targetString.length() + 1, false);
        table[0] = true;

        for(int i = 0; i < targetString.length() + 1; i++) {   
            if(table[i] == true) {
                for(std::string &word: wordBank) {

                    int pos = targetString.find(word, i);

                    if(pos == i) {

                        table[i + word.length()] = true;
                    }
                }
            }
        }
        return table[targetString.length()];
} 

void printRes(std::string targetString,  
        std::vector<std::string> &wordBank, bool res) {

    std::cout << "TargetString: " << targetString << " \nWords: [";
    for(int i = 0; i < wordBank.size(); i++) {
        if(i > 0)std::cout << ',';
        std::cout << wordBank[i];
    }
    std::cout << "]\nResult: " <<  
            (res ? "true": "false") << "\n" << std::endl;
}
int main() {

    std::string targetString = "abcdef";
    std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
    bool res = canConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = "skateboard";
    wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    res = canConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = "enterapotentpot";
    wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
    res = canConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = std::string(39, 'e') + "f";
    wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    std::unordered_map<std::string, bool> memo;
    res = memoCanConstruct(targetString, wordBank, memo);
    printRes(targetString, wordBank, res);
    
    targetString = "enterapotentpot";
    wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
    res = tabCanConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);
    return 0;
}