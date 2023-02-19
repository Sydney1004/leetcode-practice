## 24. Swap Nodes in Pairs

**Link:** [24. Swap Nodes in Pairs](https://leetcode.cn/problems/swap-nodes-in-pairs/)

**My solution:** 

Set a dummy node whose next points to head

let temp1 = curr->next

let temp2 = curr->next->next->next

 - step 1: set curr->next = curr->next->next
 - step 2: set curr->next->next = temp1
 - step 3: set curr->next->next->next = temp2

 ```
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = dummy;
    while(curr->next and curr->next->next) {
        ListNode* temp = curr->next;
        ListNode* temp2 = curr->next->next->next;

        curr->next = curr->next->next;
        curr->next->next = temp; // originally is curr->next->next->next
        curr->next->next->next = temp2;
        curr = curr->next->next;
    }
    return dummy->next;
}
 ```

**Time Complexity:**  O(N)

**Space Complexity:**  O(1)


## 19. Remove Nth Node From End of List

**Link:** [19. Remove Nth Node From End of List](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

**My solution:** 

Have dummy node whose next is head.
Takeaway here is to let fast be n+1 step ahead of slow. Then by the time fast reaches the end of the linked list, fast points at the previous node of the nth from the last node.

```
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = dummy;
    while (n >= 0 and fast) {
        fast = fast->next;
        n--;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;

}
};
```

**Time Complexity:**  O(Length of the linked list)

**Space Complexity:**  O(1)


## 142. Linked List Cycle II

**Link:** [142. Linked List Cycle II](https://leetcode.cn/problems/linked-list-cycle-ii/)

**My solution:** 

Todo
