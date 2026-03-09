
class Solution {
private:
    TreeNode* convert(const std::vector<int>& nums, int left, int right) {

        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convert(nums, left, mid - 1);
        root->right = convert(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return convert(nums, 0, nums.size() - 1);
    }
};