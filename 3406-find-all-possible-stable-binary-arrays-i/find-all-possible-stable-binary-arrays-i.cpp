class Solution {
public:
    // Recursive function to solve the problem
    int solve(int zero, int one, int limit, int prev, vector<vector<vector<int>>>& dp) {
        int mod = 1000000007;

        // Bounds checking
        if (zero < 0 || one < 0) {
            return 0;
        }
        
        // Base case: If both zero and one are zero, we have a stable binary array
        if (zero == 0 && one == 0) {
            return 1;
        }

        // Memoization: Check if the result for the current state is already calculated
        if (dp[zero][one][prev+1] != -1) {
            return dp[zero][one][prev+1];
        }

        int ans = 0;
        // Recursive calls for adding zeros and ones
        if (prev != 0) {
            for (int i = 1; i <= limit; i++) {
                ans = (ans + solve(zero - i, one, limit, 0, dp)) % mod;
            }
        }
        if (prev != 1) {
            for (int i = 1; i <= limit; i++) {
                ans = (ans + solve(zero, one - i, limit, 1, dp)) % mod;
            }
        }
        // Memoize the result and return
        return dp[zero][one][prev+1] = ans % mod;
    } 

    // Main function to calculate the number of stable binary arrays
    int numberOfStableArrays(int zero, int one, int limit) {
        // Initialize memoization array with -1
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(3, -1)));
        // Call the recursive function with initial parameters
        return solve(zero, one, limit, -1, dp);
    }
};