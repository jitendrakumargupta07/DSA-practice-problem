class Solution {
public:
    int helper(int i, int j ,vector<int>& nums, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = INT_MIN;
        for(int ind=i; ind<=j;ind++){
            int bust = nums[i-1] * nums[ind] * nums[j+1] + helper(i,ind-1,nums,dp) + helper(ind+1,j,nums,dp);
            maxi = max(bust,maxi);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        return helper(1,n,nums,dp);
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        for(int i=n;i>0;i--){
            for(int j=0;j<n+1; j++){
                if(i>j) continue;
                int maxi = INT_MIN;
                for(int ind = i; ind<=j; ind++){
                    int bust = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(bust,maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};