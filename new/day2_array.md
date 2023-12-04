## 977. Squares of a Sorted Array

**My solution:** 

```
vector<int> sortedSquares(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (abs(nums[l]) > abs(nums[r])) {
            ans[i] = nums[l] * nums[l];
            l++;
        }
        else {
            ans[i] = nums[r] * nums[r];
            r--;
        }
    }
    return ans;
}
```

**Time Complexity:**  O(N)

**Space Complexity:**  O(1)


## 209. Minimum Size Subarray Sum

**My solution:** 


```
int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0;
    int ans = INT_MAX;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        while (sum >= target) {
            ans = min(ans, i - start + 1);
            sum -= nums[start++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
```  
       
**Time Complexity:**  O(N)

**Space Complexity:**  O(1)

## 59. Spiral Matrix II

**My solution:** 
- need to visualize it, simply walk through each entry.

```
vector<vector<int>> generateMatrix(int n) {
    // init a matrix
    vector<vector<int>> m(n, vector<int>(n, 0));
    int right = n - 1;
    int left = 0;
    int top = 0;
    int bottom = n - 1;
    int val = 1;
    while (val <= n*n) {
        for (int i = left; i <= right; ++i) {
            m[top][i] = val++;
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            m[i][right] = val++;
        }
        right--;
        for (int i = right; i >= left; --i) {
            m[bottom][i] = val++;
        }
        bottom--;
        for (int i = bottom; i >= top; --i) {
            m[i][left] = val++;
        }
        left++;
    }
    return m;
}
```