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
    bool BST(TreeNode *root,long long &prev){
        if(!root){
            return 1;
        }
        if(!BST(root->left,prev)){
            return 0;
        }
        if(root->val <= prev){
            return 0;
        }
        prev = root->val;
        return BST(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return BST(root,prev);
    }
};