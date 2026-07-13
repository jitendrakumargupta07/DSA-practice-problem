class Solution {
public:
    bool subsetSum(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true; 
        if (i == 0) return nums[0] == target; 
        if (dp[i][target] != -1) return dp[i][target];

        bool notTaken = subsetSum(i-1, target, nums, dp);
        bool taken = false;
        if (nums[i] <= target) 
            taken = subsetSum(i-1, target - nums[i], nums, dp);

        return dp[i][target] = notTaken || taken;
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return subsetSum(n-1, target, nums, dp);
    }
};