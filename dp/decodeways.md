## random review:
OOP allows objects to interact with each other using four basic principles: encapsulation, inheritance, polymorphism, and abstraction

## 91. Decode Ways
***Solution:*** <br>
initialize a list of f with 0 entries \
if f[i] != 0: \
&nbsp;&nbsp;&nbsp;f[i] = f[i - 1] \
if 10 <= f[i - 1] || f[i] <=26:\
&nbsp;&nbsp;&nbsp;f[i] += f[i - 2]
```
int numDecodings(string s) {
    if (s[0] == '0') {
        return 0;
    }
    vector<int> memo(s.length() + 1);
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i <= s.length(); ++i) {
        int one = stoi(s.substr(i - 1, 1));
        if (0 < one && one < 10) {
            memo[i] = memo[i - 1];
        }
        int two = stoi(s.substr(i - 2, 2));
        if (10 <= two && two <= 26) {
            memo[i] += memo[i - 2];
        }
    }
    return memo[s.length()];
}
```  