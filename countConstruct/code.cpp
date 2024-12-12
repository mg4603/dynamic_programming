#include <vector>
#include <iostream>
#include <unordered_map>

int countConstruct(std::string targetString,  
                std::vector<std::string> &wordBank) {
    
    if(targetString == "")return 1;

    int countWays = 0;
    for(auto &word: wordBank) {
        if(targetString.find(word) == 0) {
            int countSuffixWays = countConstruct( 
                            targetString.substr(word.length()), 
                            wordBank);
            countWays += countSuffixWays;
        }
    }
    return countWays;
}

int memoCountConstruct(std::string targetString, 
                std::vector<std::string> &wordBank,
                std::unordered_map<std::string, int> &memo){

    if(targetString == "")return 1;
    if(memo.count(targetString))return memo[targetString];
    
    int countWays = 0;

    for(auto &word: wordBank) {
        if(targetString.find(word)) {
            int countSuffixWays = memoCountConstruct(
                                    targetString.substr(word.length()),
                                    wordBank, memo);
            countWays += countSuffixWays;
        }
    }
    memo[targetString] = countWays;
    return countWays;
}

int tabCountConstruct(std::string targetString, 
            std::vector<std::string> &wordBank) {

        std::vector<int> table(targetString.length() + 1, 0);
        table[0] = 1;

        for(int i = 0; i < targetString.length() + 1; i++) {

            if(table[i] > 0) {
                for(std::string &word: wordBank) {
                    int pos = targetString.find(word, i);

                    if(pos == i) {
                        table[i + word.length()] += table[i];
                    }
                }
            }
        }

        return table[targetString.length()];
}

void printRes(std::string targetString,  
        std::vector<std::string> &wordBank, int res) {

    std::cout << "TargetString: " << targetString << " \nWords: [";
    for(int i = 0; i < wordBank.size(); i++) {
        if(i > 0)std::cout << ',';
        std::cout << wordBank[i];
    }
    std::cout << "]\n# ways to form " << targetString << ": " <<  
            res << "\n" << std::endl;
}

int main() {
    std::string targetString = "abcdef";
    std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
    int res = countConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = "skateboard";
    wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    res = countConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = "enterapotentpot";
    wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
    res = countConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = "purple";
    wordBank = {"purp", "p", "ur", "le", "purpl"};
    res = countConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    targetString = std::string(39, 'e') + "f";
    wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    std::unordered_map<std::string, int> memo;
    res = memoCountConstruct(targetString, wordBank, memo);
    printRes(targetString, wordBank, res);

    targetString = "enterapotentpot";
    wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
    res = tabCountConstruct(targetString, wordBank);
    printRes(targetString, wordBank, res);

    return 0;
}