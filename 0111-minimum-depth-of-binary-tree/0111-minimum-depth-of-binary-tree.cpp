class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        // If left child is NULL
        if (!root->left)
            return 1 + minDepth(root->right);

        // If right child is NULL
        if (!root->right)
            return 1 + minDepth(root->left);

        // If both children exist
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
