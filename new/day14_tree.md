## 144. Binary Tree Preorder Traversal

recursion:
```
void traverse(TreeNode* curr, vector<int>& ans) {
    if (!curr) return;
    ans.push_back(curr->val);
    traverse(curr->left, ans);
    traverse(curr->right, ans);

}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(root, ans);
    return ans;
}
```

iteration:
```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    if (!root) return ans;
    st.push(root);
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return ans;
}
```

## 94. Binary Tree Inorder Traversal

```
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}
```