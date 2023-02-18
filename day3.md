## 206. Reverse Linked List

**Link:** [206. Reverse Linked List](https://leetcode.cn/problems/reverse-linked-list/)

**My solution:** 

 - Just modify next in place

```
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;   
```  

**Time Complexity:**  O(N)

**Space Complexity:**  O(1)


## 203. Remove Linked List Elements

**Link:** [203. Remove Linked List Elements](https://leetcode.cn/problems/remove-linked-list-elements/)

**My solution:** 

```
    ListNode* removeElements(ListNode* head, int val) {
        while (head and head->val == val) {
            head = head->next;
        }
        if (!head) return nullptr;
        
        ListNode* dummy = head;
        while (head->next) {
            if (head->next->val == val) {
                head->next = head->next->next;
            }
            else {
                head = head->next;
            }
        }
        return dummy;
    }
};
```

**Time Complexity:**  O(N)

**Space Complexity:**  O(1)


## 707. Design Linked List

**Link:** [707. Design Linked List](https://leetcode.cn/problems/design-linked-list/)

**My solution:** 

 - Have some errors currently, might come back to this question after the midterm.
