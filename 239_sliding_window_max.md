## 239. Sliding Window Maximum

**My solution:** 
Maintain a monotonic queue. Only insert the element to the queue if it is greater than the back of the queue. So the front of the queue is always the max value in the sliding window.
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; ++i) { // create the first sliding window
            while (!dq.empty() and dq.back() < nums[i]) { // if dq.back() < nums[i], then we can ignore dq.back() by poping it since it is def not the max val within this window.
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        for (int i = k; i < nums.size(); ++i) {
            if (!dq.empty() and dq.front() == nums[i - k]) dq.pop_front();
            while (!dq.empty() and dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};
```
**Time Complexity:**  O(n)

**Space Complexity:**  O(k)