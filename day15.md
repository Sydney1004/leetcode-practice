## 102. Binary Tree Level Order Traversal

**Link:** [102. Binary Tree Level Order Traversal](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

**My solution:** 

The takeaway here is to have a for-loop inside a while loop, the for-loop constructs a vector containing val at the same level. After the for-loop, the length of the deque will be the number of nodes at that level.

```
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    deque<TreeNode*> dq;
    dq.push_back(root);
    while (!dq.empty()) {
        int len = dq.size();
        vector<int> partial;
        for (int i = 0; i < len; ++i) {
            TreeNode* curr = dq.front();
            partial.push_back(curr->val);
            dq.pop_front();
            if (curr->left) dq.push_back(curr->left);
            if (curr->right) dq.push_back(curr->right);
        }
        ans.push_back(partial);
    }
    return ans;
}
 ```

## 107. Binary Tree Level Order Traversal II

**Link:** [107. Binary Tree Level Order Traversal II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

**My solution:** 

Same as 102. Binary Tree Level Order Traversal, but reverse the returning vector.

## 199. Binary Tree Right Side View

**Link:** [199. Binary Tree Right Side View](https://leetcode.cn/problems/binary-tree-right-side-view/)

**My solution:** 
Similar to the previous problems.

```
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    deque<TreeNode*> dq;
    dq.push_back(root);
    while (!dq.empty()) {
        int len = dq.size();
        TreeNode* curr;
        for (int i = 0; i < len; ++i) {
            curr = dq.front();
            dq.pop_front();
            if (curr->left) dq.push_back(curr->left);
            if (curr->right) dq.push_back(curr->right);
        }
        ans.push_back(curr->val);
    }
    return ans;
}
```