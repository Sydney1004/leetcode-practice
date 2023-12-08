## Unordered_map

Hash collisions: separate chaining and linear or quadratic probing <br>
Hash tables can be implemented in C++ using a combination of arrays and linked lists.

## 202. Happy Number

```
bool isHappy(int n) {
    unordered_set<int> my_set;
    int sum = 0;
    while (my_set.find(sum) == my_set.end()) {
        my_set.insert(sum);
        sum = 0;
        while (n > 0) {
            int val = n % 10;
            sum += val * val;
            n /= 10;
        }
        if (sum == 1) return true;
        n = sum;
        
    }
    return false;
}
```

## 349. Intersection of Two Arrays

```
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    for (int i : s1) {
        if (s2.find(i) != s2.end()) {
            ans.push_back(i);
        }
    }
    return ans;
}
```


## 242. Valid Anagram
```
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int arr[26] = {0};
    for (int i = 0; i < s.length(); ++i) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }
    for (int i : arr) {
        if (i != 0) return false;
    }
    return true;
}
```