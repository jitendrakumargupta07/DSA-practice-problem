class Solution {
public:
    void subset(int ind, vector<int>& list, vector<vector<int>>& ans, vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(list);
            return;
        }

        // Include nums[ind]
        list.push_back(nums[ind]);
        subset(ind + 1, list, ans, nums);
        list.pop_back();

        // Skip duplicates
        for (int i = ind + 1; i < nums.size(); i++) {
            if (nums[i] != nums[ind]) {
                subset(i, list, ans, nums);
                return;
            }
        }

        // If all remaining numbers are duplicates
        subset(nums.size(), list, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> list;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        subset(0, list, ans, nums);
        return ans;
    }
};