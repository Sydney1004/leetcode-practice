## array
- a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.


## 704. Binary Search

**Link:** [704 Binary Search](https://leetcode.com/problems/binary-search/)

**My solution:** 
- left side inclusive, right side exclusive
```
int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            r = mid;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        }
        else return mid;
    }
    return -1;
}
```

**Time Complexity:**  O(logN)

**Space Complexity:**  O(1)


## 27. Remove Element

**Link:** [27. Remove Element](https://leetcode.com/problems/remove-element/)

**My solution:** 

 - use 2 pointers

```
    for (quick = 0; quick < nums.size(); ++quick):
        if nums[quick] != val:
            nums[slow] = nums[quick]
            ++slow
    return slow
```  
 - Or start from both ends
 ```
int removeElement(vector<int>& nums, int val) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        if (nums[l] == val) {
            nums[l] = nums[r];
            r--;
        }
        else {
            l++;
        }
    }
    return l;
}

 ```
       
**Time Complexity:**  O(N)

**Space Complexity:**  O(1)