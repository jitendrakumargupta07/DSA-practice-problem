class Solution {
public:
    void findCombination(int ind, int sum, vector<int>& list, 
                         vector<vector<int>>& ans, vector<int>& nums) {
        if(sum == 0) {                 // found valid combination
            ans.push_back(list);
            return;
        }
        if(sum < 0 || ind == nums.size()) return;

        // Pick current element (can reuse)
        list.push_back(nums[ind]);
        findCombination(ind, sum - nums[ind], list, ans, nums);
        list.pop_back();

        // Skip current element
        findCombination(ind + 1, sum, list, ans, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        findCombination(0, target, list, ans, nums);
        return ans;
    }
};