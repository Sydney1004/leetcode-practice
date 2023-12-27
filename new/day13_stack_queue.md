### 239. Sliding Window Maximum

```
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    // 1. push back index to the deque, pop front if small
    deque<int> dq;
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    // 2. if front index out of bound, pop it
    for (int i = k; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() == i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}
```
### 347. Top K Frequent Elements

```
class Solution {
public:
    class cmp {
    public:
        // Comparator function
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            // min heap
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto& i : mp) {
            pq.push({i.first, i.second});
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;;
    }
};
```