## 15.threeSum

**My solution:** 
Sort the vector first, then use 3 indices, i, left, right.
Start with i = 0, left = i + 1, right = nums.size() - 1. Getting rid of the repeatitive part is tricky. if nums[i] == nums[i-1], then i++;

```
vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 and nums[i] == nums[i-1]) continue; // get rid of repeated i

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) right--;
            else if (nums[i] + nums[left] + nums[right] < 0) left++;
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                while (left < right and nums[left] == nums[left + 1]) left++;
                while (left < right and nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
        }


    }
    return ans;
}
```
    
**Time Complexity:**  O(${n^2}$)

**Space Complexity:**  O(1)


