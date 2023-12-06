## static variable/function
1. A variable declared static within the body of a function maintains its value between invocations of the function.
2. A variable declared static within a module (but outside the body of a function) is accessible by all functions within that module. However, it is not accessible by functions from other modules.
3. static members exist as members of the class rather than as an instance in each object of the class. There is only a single instance of each static data member for the entire class.
4. Non-static member functions can access all data members of the class: static and non-static. Static member functions can only operate on the static data members.
5. C functions declared static within a module may only be called by other functions within that module (file scope).

## 344. Reverse String

**My Solution**
```
void reverseString(vector<char>& s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++; r--;
    }
}
```

## 541. Reverse String II

**My Solution**

If less than k left reverse all, if less than 2k left, reverse first k
```
void reverse_str(string &s, int l, int r) {
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        r--; l++;
    }
}
string reverseStr(string s, int k) {
    int start = 0;
    while (start < s.length()) {
        if (start + k > s.length()) {
        reverse_str(s, start, s.length() - 1);
        }
        else reverse_str(s, start, start + k - 1);
        start += 2*k;
    }
    return s;
}
```

## 151. Reverse Words in a String

**My solution**

First push each word to a stack, then just pop from stack
```
string reverseWords(string s) {
    string ans;
    stack<string> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') continue;
        string word = "";
        while (i < s.length() && s[i] != ' ') {
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
        ans += " ";
    }
    ans.pop_back();
    return ans;
}
```

