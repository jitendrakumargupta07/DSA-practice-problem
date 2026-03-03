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
using namespace std;

class Solution {
public:
    int dfs(TreeNode* node){
        int left = 0, right = 0;

        if(node == nullptr){
            return 0;
        }

        if (node->left != nullptr){
            left = dfs(node->left);
        }

        if (node->right != nullptr){
            right = dfs(node->right);
        }
        return max(left, right) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};