## 42. Trapping Rain Water
(https://leetcode.cn/problems/trapping-rain-water/)

method 1: use 2 pointers, for each column, height[i], the amount of rain it can trap is the min(left highest, right highest) minus height[i].
```
int trap(vector<int>& height) {
    // exceed time limit
    int ans = 0;
    for (int i = 1; i < height.size() - 1; ++i) {
        int rheight = height[i];
        int lheight = height[i];
        for (int j = i - 1; j >= 0; --j) {
            if (height[j] > lheight) lheight = height[j];
        }
        for (int j = i + 1; j < height.size(); ++j) {
            if (height[j] > rheight) rheight = height[j];
        }
        ans += min(lheight, rheight) - height[i];

    }
    return ans;
}
```

method 2:
Use more space for time complexity. Have a maxLeft and a maxRight vector to record the max right height at index i.

```
int trap(vector<int>& height) {
    int ans = 0;
    vector<int> maxLeft (height.size(), 0);
    vector<int> maxRight (height.size(), 0);
    maxLeft[0] = height[0];
    for (int i = 1; i < height.size(); ++i) {
        maxLeft[i] = max(height[i - 1], maxLeft[i - 1]);
    }
    maxRight[height.size() - 1] = height[height.size() -1];

    for (int i = height.size() - 2; i >= 0; --i) {
        maxRight[i] = max(height[i + 1], maxRight[i + 1]);
    }
    for (int i = 1; i < height.size() - 1; ++i) {
        int val = min(maxRight[i], maxLeft[i]) - height[i];
        if (val > 0) ans += val;
    }
    return ans;
}
```

method 3:
monotonic stack

```
int trap(vector<int>& height) {
    int ans = 0;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < height.size(); ++i) {
        while (!st.empty() && height[i] > height[st.top()]) { 
            int mid = st.top();
            st.pop();
            // if st not empty then, st.top() > mid and height[i] > mid
            if (!st.empty()) {
                int h = min(height[st.top()], height[i]) - height[mid];
                int w = i - st.top() - 1;
                ans += h * w;
            }

        }
        st.push(i);
    }
    return ans;
}
```