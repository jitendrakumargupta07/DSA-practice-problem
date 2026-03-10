class Solution {
public:
    std::vector<std::vector<int>> ans;
    int target;
    void dfs(TreeNode* root, std::vector<int>& path, int sum) {
        if (!root) return;
        int val = root->val;
        if (!root->left && !root->right) {
            // edge case: leaf node
            if (sum + val != target) return;
            path.push_back(val);
            ans.push_back(path);
            path.pop_back(); // context restoring
            return;
        }
        // non-edge case: 
        sum += val;
        path.push_back(root->val);
        dfs(root->left, path, sum);
        dfs(root->right, path, sum);
        path.pop_back();
    }
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        ans.clear();
        target = targetSum;
        std::vector<int> currentPath;
        dfs(root, currentPath, 0);
        return ans;
    }
};