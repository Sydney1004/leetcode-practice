## 131. Palindrome partition

**Link:** [131. Palindrome partition](https://leetcode.cn/submissions/detail/419606230/)

**My solution:** 

Starting by string length of 1

i.e.
```
"aab" -> "a", "ab" -> "a", "a", "b"
"aab" -> "ab", "b" 
"aab" -> "abb" 
```

The stoping condition is when the start index of the partition equal to the length of the string.

```
class Solution {
    vector<vector<string>> ans;
    vector<string> partial;
public:
    bool is_palindrome(string s) {
        int j = s.length() - 1;
        for (int i = 0; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backtracking(string s, int start) { 
        if (start == s.length()) { // missed the condition here
            ans.push_back(partial);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (is_palindrome(s.substr(start, i - start + 1))) {
                partial.push_back(s.substr(start, i - start + 1));
                backtracking(s, i + 1);
                partial.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};
```  

