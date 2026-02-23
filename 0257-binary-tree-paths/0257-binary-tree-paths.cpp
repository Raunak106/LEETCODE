class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;
        
        path += to_string(root->val);
        
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }
        
        path += "->";
        
        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};
