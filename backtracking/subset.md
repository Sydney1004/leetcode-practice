***90. Subsets II***

The main takeaway here is " if (i > start && nums[i] == nums[i-1]) continue;" to get rid of the repetitive elements. If (i > start) it means nums[start] has been ignore becasue of the pop_back() at the end of the for loop. If we ignore nums[start] and nums[start + i] == nums[start], we should also ignore nums[start + i];

```
vector<int> partial;
vector<vector<int>> ans;
void backtrack(vector<int>& nums, int start) {
    ans.push_back(partial);

    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i-1]) continue;
        partial.push_back(nums[i]);
        backtrack(nums, i + 1);
        partial.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    return ans;
}
```