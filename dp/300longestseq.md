
***Solution:***
memo[i] represents the length of the longest increasing sequence for nums[0, i], i inclusive.
Just compare nums[i] with nums[j] where j < i
if nums[i] > nums[j], then the length of the longest increasing sequence increments by 1.

```
int lengthOfLIS(vector<int>& nums) {
    vector<int> memo(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }
    sort(memo.begin(), memo.end());
    return memo.back();
}
```