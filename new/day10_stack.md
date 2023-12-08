## Stack
-  container adaptor 
- implementation:
    - array/vector, push is constant, linear when resizing vector, amortized constant
    - singly linked list
    - default: deque

## Queue
- container adaptor
- implementation:
    - circular array
    - singly linked list
    - default: deque

## Container adaptor
constructed by taking one of the sequential containers given above and "adapting" (restricting/modifying) its interface to provide the desired behavior.

## 232. Implement Queue using Stacks

```
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
```

## 225. Implement Stack using Queues

Use one queue or two queues.