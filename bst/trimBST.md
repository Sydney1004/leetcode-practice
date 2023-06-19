***669. Trim a Binary Search Tree***

*My solution:*

If the value of the root is less than low, then the left subtree of root and root itself are not needed, therefore return the trimmed right subtree.

```
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
```
***501. Find Mode in Binary Search Tree***

*Solution:*

Use inorder traversal.
```
vector<int> ans;
int count = 1;
int max_count = INT_MIN;
TreeNode* pre = nullptr;
void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    if (pre) {
        if (pre->val == root->val) {
            count++;
        }
        else count = 1;
    
    }
    if (count > max_count) {
        ans.clear();
        max_count = count;
        ans.push_back(root->val);
    }
    else if (count == max_count) {
        ans.push_back(root->val);
    }
    pre = root;
    traverse(root->right);
}
vector<int> findMode(TreeNode* root) {
    traverse(root);
    return ans;
}
```