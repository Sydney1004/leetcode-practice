## smart pointers
Smart pointers are used to make sure that an object is deleted if it is no longer used (referenced).
- The unique_ptr<> template holds a pointer to an object and deletes this object when the unique_ptr<> object is deleted.
- The shared_pointer is a reference counting smart pointer that can be used to store and pass a reference beyond the scope of a function. 
- The weak_pointer provides a non-owning reference to an object that is managed by a shared pointer. Unlike a shared pointer, a weak pointer does not increment the reference count of the managed object, so it does not affect the lifetime of the object.

- std::unique_ptr<D> p = std::make_unique<D>();
- std::shared_ptr<D> p = std::make_shared<D>();

## 150. Evaluate Reverse Polish Notation

```
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string token : tokens) {
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            st.push(stoi(token));
        }
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            if (token == "+") st.push(val1 + val2);
            else if (token == "-") st.push(val1 - val2);
            else if (token == "*") st.push(val1 * val2);
            else if (token == "/") st.push(val1 / val2);
        }
    }
    return st.top();
}
```

## 1047. Remove All Adjacent Duplicates In String

Use the idea of stack
```
string removeDuplicates(string s) {
    string ans = "";
    for (char c:s) {
        if (!ans.empty() && c == ans.back()) ans.pop_back();
        else ans.push_back(c);
    }
    return ans;
}
```

## 20. Valid Parentheses

```
bool isValid(string s) {
    stack<char> st;
    for (auto c : s) {
        if (c == '(') {
            st.push(')');
        }
        else if (c == '[') {
            st.push(']');
        }
        else if (c == '{') {
            st.push('}');
        }
        else {
            if (st.empty() || c != st.top()) return false;
            st.pop();
        }
    }
    return st.empty();
}
```