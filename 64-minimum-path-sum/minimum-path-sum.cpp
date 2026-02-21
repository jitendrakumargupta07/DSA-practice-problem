class Solution {
public:
    void solve(int r,int c,int sum,vector<vector<int>>& grid,int & minn,vector<vector<int>>& dp){
        if(r<0 || c<0) return ;

        if(dp[r][c]!=-1 && sum>=dp[r][c]) return;

        dp[r][c]=sum;

        if(r==0 && c==0){
            minn=min(minn,sum);
            return;
        }

        if(sum>=minn) return;

        if (c > 0) solve(r, c-1, sum + grid[r][c-1], grid, minn,dp);
        if (r > 0) solve(r-1, c, sum + grid[r-1][c], grid, minn,dp);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minn=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        solve(m-1,n-1,grid[m-1][n-1],grid,minn,dp);
        return minn;
    }
};