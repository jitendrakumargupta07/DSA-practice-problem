class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
     
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0];

        for (int k = 1; k <= 2*n - 2; k++) {
            vector<vector<int>> new_dp(n, vector<int>(n, INT_MIN));

            for (int r1 = min(k, n-1); r1 >= 0; r1--) {
                int c1 = k - r1;
                if (c1 < 0 || c1 >= n || grid[r1][c1] == -1) continue;

                for (int r2 = min(k, n-1); r2 >= 0; r2--) {
                    int c2 = k - r2;
                    if (c2 < 0 || c2 >= n || grid[r2][c2] == -1) continue;

                    int prev_best = INT_MIN;
                    if (r1 > 0 && r2 > 0) prev_best = max(prev_best, dp[r1-1][r2-1]);
                    if (r1 > 0 && c2 > 0) prev_best = max(prev_best, dp[r1-1][r2]); 
                    if (c1 > 0 && r2 > 0) prev_best = max(prev_best, dp[r1][r2-1]);
                    if (c1 > 0 && c2 > 0) prev_best = max(prev_best, dp[r1][r2]); 

                    if (prev_best < 0) continue;

                    prev_best += (r1 == r2 ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2]);
                    new_dp[r1][r2] = max(new_dp[r1][r2], prev_best);
                }
            }
            dp.swap(new_dp);
        }
        return max(0, dp[n-1][n-1]);
    }
};