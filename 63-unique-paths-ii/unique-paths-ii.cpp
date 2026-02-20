class Solution {
public:
        int helper(int i, int j, int m ,int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n || grid[i][j]==1){
            return 0;

        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;

        ans+=helper(i+1,j, m, n ,grid,dp)+ helper(i,j+1,m,n,grid,dp);
        return dp[i][j]=ans;
    
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[m-1][n-1]==1){
            return 0;
        }

        vector<vector<int>>dp(m ,vector<int>(n,-1));
        return helper(0,0,m,n,grid,dp);
        
    }
};