## 139. Word Break
https://leetcode.cn/problems/word-break/

**My solution:** 

memo[i] represents if s[0: i - 1] can be segmented into a space-separated sequence of one or more dictionary words. 

if memo[i] == true, then we look at if s[i : i + word.length] is in the dictionary, if so memo[i + word.length] = true
```
bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> memo(s.length() + 1, false);
        // memo[i] represent if s of length i can be brokedown
        memo[0] = true;
       
        for (int i = 0; i < s.length(); ++i) {
            if (!memo[i]) continue;
            for (auto word : wordDict) {
                if (s.substr(i, word.size()) == word) {
                    memo[i + word.size()] = true;
                }
            }
        }
        return memo[s.length()];
}
```