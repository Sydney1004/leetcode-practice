## 131. Palindrome-partitioning

**Link:** [131. Palindrome-partitioning](https://leetcode.cn/problems/palindrome-partitioning/)

**My solution:** 

```
void backtracking(string &s, int start_idx);
bool palindrome(string s);

vector<vector<string>> partition(string s)
{
    backtracking(s, 0);
    return ans;
}

void backtracking(string &s, int start_idx)
{
    if (start_idx == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = start_idx; i <= s.length(); ++i)
    {
        string sub_str = s.substr(start_idx, i - start_idx + 1);
        if (palindrome(sub_str))
        {
            path.push_back(sub_str);
        }
        else
        {
            continue;
        }
        backtracking(s, i + 1);
        path.pop_back();
    }
}

bool palindrome(string s)
{
    int j = s.length() - 1;
    for (int i = 0; i < j; ++i, --j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

```  

