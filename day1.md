## 704. Binary Search

**Link:** [704 Binary Search](https://leetcode.com/problems/binary-search/)

**My solution:** 

 - Too shameful to admit that I still wasn't sure when to use <= or < in the while loop. But just figured it out!

```
    if the range is [left, right]
    
    then while left <= right

    Since left == right has a meaning    
```  
```
    if the range is [left, right)

    then while left < right

    since left won't euqal to right
```
       

**Time Complexity:**  O(logN)

**Space Complexity:**  O(1)


## 27. Remove Element

**Link:** [27. Remove Element](https://leetcode.com/problems/remove-element/)

**My solution:** 

 - Can use two pointers on this one

```
    for (quick = 0; quick < nums.size(); ++quick):
        if nums[quick] != val:
            nums[slow] = nums[quick]
            ++slow
    return slow
```  
 - Or start from both ends
 ```
    while(left <= right):
        if nums[left] == val:
            nums[left] = nums[right]
            right--
        else
            left++
    return right + 1
 ```
       

**Time Complexity:**  O(N)

**Space Complexity:**  O(1)