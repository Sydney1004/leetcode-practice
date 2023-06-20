***93. Restore IP Addresses***

Input: s = "25525511135"

Output: ["255.255.11.135","255.255.111.35"]

Split the input string by dots, then examine if each part is valid by passing in s.substr() to isValidIP().



```
vector<string> ans;
bool isValidIP(string s) {
    // prevent cases like s = "012" and s is out of range
    if ((s[0] == '0' && s.length() > 1) || s.length() > 3) return false;
    int ip = stoi(s);
    if (ip > 255) return false;
    return true;
}
void backtrack(string s, int numDot, int start) {
    if (numDot == 3) {
        if (start == s.length()) return;    // the dot is at the end of the string, which is not valid
        if (isValidIP(s.substr(start))) ans.push_back(s);
        return;
    }

    for (int i = start; i < s.length(); ++i) {
        if (isValidIP(s.substr(start, i - start + 1))) {
            s.insert(i + 1, ".");
            numDot++;
            backtrack(s, numDot, i + 2);
            s.erase(i + 1, 1);
            numDot--;
        }
        else break;
    }

}
vector<string> restoreIpAddresses(string s) {
    backtrack(s, 0, 0);
    return ans;
}
```