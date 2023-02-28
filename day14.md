## 144. Binary Tree Preorder Traversal

**Link:** [144. Binary Tree Preorder Traversal](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

**My solution:** 

preorder travesal visits the root node first, followed by the left subtree, and then the right subtree

```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);
    return ans;
}

void traversal(TreeNode* root, vector<int> &vec) {
    if (!root) return;
    vec.push_back(root->val);
    traversal(root->left, vec);
    traversal(root->right, vec);
}
 ```

## 145. Binary Tree Postorder Traversal

**Link:** [145. Binary Tree Postorder Traversal](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

**My solution:** 

postorder travesal visits left subtree, followed by the right subtree, and then the root node.

```
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);
    return ans;
}

void traversal(TreeNode* root, vector<int> &vec) {
    if (!root) return;
    traversal(root->left, vec);
    traversal(root->right, vec);
    vec.push_back(root->val);
}
```

## 94. Binary Tree Inorder Traversal

**Link:** [94. Binary Tree Inorder Traversal](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

**My solution:** 
Inorder travesal visits left subtree, followed by the root node, and then the right subtree.

```
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);
    return ans;
}

void traversal(TreeNode* root, vector<int> &vec){
    if (!root) return;
    traversal(root->left, vec);
    vec.push_back(root->val);
    traversal(root->right, vec);
}
```