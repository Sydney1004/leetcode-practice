## 145. Binary Tree Postorder Traversal
**Link** [https://leetcode.cn/problems/binary-tree-postorder-traversal/]

**My solution using iterative:** 
Postorder visits the left, then right, then middle.

We can first visit the middle then right then left, finally reverse **ans**.
```
vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    stack<TreeNode*> st;
    vector<int> ans;
    st.push(root);
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if (curr->left) st.push(curr->left);
        if (curr->right) st.push(curr->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```