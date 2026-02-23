class Solution {
public:
    int maxSum = INT_MIN;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));
        
        int currentPath = root->val + leftGain + rightGain;
        
        maxSum = max(maxSum, currentPath);
        
        return root->val + max(leftGain, rightGain);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
