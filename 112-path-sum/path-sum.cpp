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
    bool dfs(TreeNode* node,int target){

        if(node == nullptr && target == 0){
            return true;
        }
        else if(node == nullptr){
            return false;
        }
        if (node->left == nullptr){
            return dfs(node->right,target - node->val);
        }
        if (node->right == nullptr){
            return dfs(node->left,target - node->val);
        }
        return (dfs(node->left,target - node->val) || dfs(node->right,target - node->val));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        return dfs(root,targetSum);
    }
};
