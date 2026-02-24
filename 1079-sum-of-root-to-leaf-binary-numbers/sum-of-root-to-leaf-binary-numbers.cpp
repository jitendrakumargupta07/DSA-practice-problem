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
    int dfs(TreeNode* root,int num, int &sum) {

        num = (num << 1) | root->val;

        if(root->left == nullptr && root->right == nullptr){
            sum += num;
        }

        if(root->left != nullptr) {
            dfs(root->left, num, sum);
        }

        if(root->right != nullptr){
            dfs(root->right, num, sum);
        }

        return sum;
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int num = 0, total = 0;
        return dfs(root, num, total);
    }
};
