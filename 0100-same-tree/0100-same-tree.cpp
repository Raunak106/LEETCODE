class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null
        if (p == nullptr && q == nullptr) return true;

        // If one is null and other is not
        if (p == nullptr || q == nullptr) return false;

        // Check current value and recurse left & right
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
