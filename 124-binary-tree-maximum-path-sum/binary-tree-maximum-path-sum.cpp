/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxSum = INT_MIN;
    
    int maxPathSumUtil(TreeNode* node) {
        if (!node) return 0;
        
        // Recursively compute max path sum for left and right subtrees
        int leftSum = max(0, maxPathSumUtil(node->left));
        int rightSum = max(0, maxPathSumUtil(node->right));
        
        // Update the maximum path sum that goes through the current node
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        
        // Return the maximum path sum that can be extended to the parent
        return node->val + max(leftSum, rightSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        return maxSum;
    }
};