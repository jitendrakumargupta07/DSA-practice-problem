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
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int leftMin = minDepth(root->left);
        int rightMin = minDepth(root->right);
        int minDep;
        if (!leftMin || !rightMin) {
            // edge case: a node with no left or right node,
            // pure comparing and using the minimum between these
            // two will cause a proble, which require special handling
            minDep = leftMin == 0 ? rightMin : leftMin;
        } else {
            minDep = min(leftMin, rightMin);
        }
        return minDep + 1;
    }
};