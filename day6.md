## 24. Swap Nodes in Pairs

**Link:** [24. Swap Nodes in Pairs](https://leetcode.cn/problems/swap-nodes-in-pairs/)

**My solution:** 

An array can be view as a simple hash table in this case, since we know there are only 26 letters, we just initialize an array of size 26 contains freq 0. Also hash table is slower and takes more space.

I used 3 for-loops but we can do this in 2.

```
    int n = s.length();
    int arr[26] = {0};
    for (int i =0; i < n;++i) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }
 ```

**Time Complexity:**  O(N)

**Space Complexity:**  O(1)


## 349. Intersection of Two Arrays

**Link:** [349. Intersection of Two Arrays](https://leetcode.cn/problems/intersection-of-two-arrays/)

**My solution:** 

I haven't used set since my data structure course. Didn't even know you could initialize it like this... In this way, we don't need to worry about repetition.

```
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> ans;
    unordered_set<int> set1(nums1.begin(), nums1.end());
    for (auto i : nums2) {
        if(set1.find(i) != set1.end()) {
            ans.insert(i);
        }
    }
    return vector<int>(ans.begin(), ans.end());
}
```

**Time Complexity:**  O(n)

**Space Complexity:**  O(n)


## 202. Happy Number

**Link:** [202. Happy Number](https://leetcode.cn/problems/happy-number/comments/)

**My solution:** 
It will enter an infinite loop, and the sum will repeat.
```
bool isHappy(int n) {
    int sum = 0;
    unordered_set<int> myset;
    while (true) {
        while(n > 0) {
            int digit = n%10;
            n = n/10;
            sum += digit * digit; 
        }
        if (sum == 1) return true;
        if (myset.find(sum) != myset.end()) return false;
        myset.emplace(sum);
        n = sum;
        sum = 0;
    }

    return true;
    
}
```

