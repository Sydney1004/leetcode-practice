## 209 Minimum Size Subarray Sum

**Solution:** 

Have a pointer pointing to the end of such subarray, and a pointer pointing to the beginning. Move the end pointer until sum >= target, then we can start to move the start pointer.

```
int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0;
    int sum = 0;
    int ans = INT_MAX;
    for (int end = 0; end < nums.size(); ++end) {
        sum += nums[end];
        while (sum >= target) {
            ans = min(end - start + 1, ans);
            sum -= nums[start++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

```
       
**Time Complexity:**  O(n)

**Space Complexity:**  O(1)


## 59. Spiral Matrix II

**Solution:** 

Draw a graph.

```
vector<vector<int>> generateMatrix(int n) {
    int l = 0, r = n - 1, t = 0, b = n - 1;
    int num = 1;
    vector<vector<int>> ans(n, vector<int>(n));

    while(num <= n*n) {
        for (int i = l; i <= r; ++i) ans[t][i] = num++;
        t++;
        for (int i = t; i <= b; ++i) ans[i][r] = num++;
        r--;
        for (int i = r; i >= l; --i) ans[b][i] = num++;
        b--;
        for (int i = b; i >= t; --i) ans[i][l] = num++;
        l++;
    }
    return ans;
}
 ```
