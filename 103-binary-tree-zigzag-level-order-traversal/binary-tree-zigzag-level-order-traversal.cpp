class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left); 
                if(node->right != nullptr) q.push(node->right); 
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res = levelOrder(root);
        for(int i=0; i<res.size(); i++){
            if(i&1){
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};