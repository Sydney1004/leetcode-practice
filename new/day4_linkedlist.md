## OOP
Object-oriented programming (OOP) is a computer programming model that organizes software design around data, or objects, rather than functions and logic.

- main principles
    - Encapsulation: This principle states that all important information is contained inside an object and only select information is exposed.
    - Abstraction: Objects only reveal internal mechanisms that are relevant for the use of other objects, hiding any unnecessary implementation code. 
    - Inheritance: Classes can reuse code from other classes. 
    - Polymorphism: The ability to associate many behaviors with one function name

## 24. Swap Nodes in Pairs
draw out the graph
```
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode();
    ListNode* pre = dummy;
    ListNode* curr = head;
    pre->next = curr;
    while (curr && curr->next) {
        pre->next = curr->next;
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = curr;
        pre = curr;
        curr= curr->next;
    }
    return dummy->next;
}
```

## 19

## 241