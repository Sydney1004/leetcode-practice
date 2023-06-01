## 151. Reverse Words in a String

**My solution:** 
Use O(1) space. Use 2 pointers to erase extra space, then reverse the whole string, then reverse each word.

```
string reverseWords(string s) {
    // 1. erase extra spaces
    int slow = 0;
    for (int i = 0; i < s.length(); ++i) { 
        if (s[i] != ' ') {
            if (slow != 0) s[slow++] = ' ';
            while (i < s.length() and s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);

    // 2. reverse the whole string
    reverse(s.begin(), s.end());

    // 3. reverse each word
    int start = 0;
    for (int i = 0; i <= s.length(); ++i) {
        if (i == s.length() || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    return s;
}
```
**Time Complexity:**  O(n)

**Space Complexity:**  O(1)