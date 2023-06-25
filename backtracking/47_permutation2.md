***47. Permutation II***

The main problem here is how to get rid of repetitive elements besides using a set. See comments.

```
vector<vector<int>> ans;
vector<int> sub;

void backtrack(vector<int>& nums, vector<bool>& used) {
    if (sub.size() == nums.size()) {
        ans.push_back(sub);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        // used[i]: if current num has been used before, we skip it
        // i > 0 && nums[i] == nums[i-1] && !used[i-1]: if current num is the same as the previous
        // num, and the previous num has been skipped, we skip it too
        if (used[i] || i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        sub.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, used);
        sub.pop_back();
        used[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrack(nums, used);
    return ans;
}
```