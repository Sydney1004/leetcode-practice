#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> memo(s.length() + 1, false);
        // memo[i] represent if s of length i can be brokedown
        memo[0] = true;
       
        for (int i = 0; i < s.length(); ++i) {
            if (!memo[i]) continue;
            for (auto word : wordDict) {
                std:: cout << s.substr(i, word.size()) << std::endl;
                if (s.substr(i, word.size()) == word) {
                    memo[i + word.size()] = true;
                }
            }
        }
        return memo[s.length()];
}

int main() {
    std::vector<std::string> wd = {"leetcodee", "code"};
    if (wordBreak("leetcode", wd)) {
        std::cout << "true\n";
    }
}