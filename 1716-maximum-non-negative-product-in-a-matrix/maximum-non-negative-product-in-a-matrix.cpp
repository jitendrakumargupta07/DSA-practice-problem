class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long mod = 1000000007;

        vector<vector<long long>> min_dp(m,vector<long long>(n));
        vector<vector<long long>> max_dp(m,vector<long long>(n));

        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                long long curr, mul, min_val = LLONG_MAX, max_val = LLONG_MIN;
                curr = grid[i][j];
                if( i == 0 && j == 0 ) {
                    min_dp[i][j] = max_dp[i][j] = curr;
                } else if( i == 0 ) {
                    max_dp[i][j] = min_dp[i][j] = curr * max_dp[i][j-1];
                } else if( j == 0 ) {
                    max_dp[i][j] = min_dp[i][j] = curr * max_dp[i-1][j];
                } else {
                    mul = (curr * max_dp[i-1][j]);
                    min_val = min(min_val, mul);
                    max_val = max(max_val, mul);

                    mul = (curr * max_dp[i][j-1]);
                    min_val = min(min_val, mul);
                    max_val = max(max_val, mul);
                    
                    mul = (curr * min_dp[i-1][j]);
                    min_val = min(min_val, mul);
                    max_val = max(max_val, mul);
                    
                    mul = (curr * min_dp[i][j-1]);
                    min_val = min(min_val, mul);
                    max_val = max(max_val, mul);

                    max_dp[i][j] = max_val;
                    min_dp[i][j] = min_val;
                }
            }
        }
        if(max_dp[m-1][n-1] < 0) return -1;
        int res = (int)((max_dp[m-1][n-1]) % mod);
        return res;
    }
};
