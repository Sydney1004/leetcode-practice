## C++ list
- List containers are implemented as doubly-linked lists

## review for today: dead lock
**Four neccessary conditions for deadlock**
1. limited resources
2. no preemption
3. hold and wait
4. cyclical chain

**Solutions:**
- impose global ordering of resources
- grab all resources atomically
- banker's algorithm
    - only grant resource if it is safe to so do, otherwise block

## 203. Remove Linked List Elements

**My Solution**
- main idea is to have a dummy head whose next points to head. And traverse the linked list starting from the dummy head, if dummy_head->next->val == val, we can delete that node by resetting dummy_head->next = dummy_head->next->next
```
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    dummy->next = head;
    while (curr && curr->next) {
        if (curr->next->val == val) {
            auto node = curr->next;
            curr->next = curr->next->next;
            delete node;
        }
        else curr = curr->next;
    }
    return dummy->next;
}
```

## 206. Reverse Linked List

```
ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    return pre;
}
```

## 707. Design Linked List

Whenever we need to manipulate the node, i feel like it is always easier to have dummyhead, which makes operations on head much easier.

```
class MyLinkedList {
    int size;
    ListNode* dummy = new ListNode();
public:
    MyLinkedList() {
        size = 0;
    }
    
    int get(int index) {
        ListNode* curr = dummy;
        while (curr && index-- >= 0) {
            curr = curr->next;
        }
        if (curr) return curr->val;
        return -1;
    }
    
    void addAtHead(int val) {
        size++;
        ListNode* newhead = new ListNode(val);
        newhead->next = dummy->next;
        dummy->next = newhead;
    }
    
    void addAtTail(int val) {
        size++;
        ListNode* newtail = new ListNode(val);
        ListNode* curr = dummy;
        while (curr && curr->next) {
            curr = curr->next;
        }
        curr->next = newtail;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        size++;
        ListNode* node = new ListNode(val);
        ListNode* curr = dummy;

        while(curr && index-- > 0) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = node;
        node->next = tmp;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        size--;
        ListNode* node = dummy;
        while (index-- > 0) {
            node = node->next;
        }
        node->next = node->next->next;
    }
};
```
