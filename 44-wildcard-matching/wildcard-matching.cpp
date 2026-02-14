class Solution {
public:
    // Function to check if a substring of S1 contains only '*'
    bool isAllStars(string &S1, int i) {
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    // Function to check if S1 matches S2 using wildcard pattern matching
    bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j >= 0)
            return false;
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return isAllStars(S1, i);

        // If the result for this state has already been calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If the characters at the current positions match or S1 has a '?'
        if (S1[i] == S2[j] || S1[i] == '?')
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
        else {
            if (S1[i] == '*') {
                // '*' can match with either an empty string or the last character in S2
                return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
            } else {
                return false;
            }
        }
    }

    // Main function to check if S1 matches S2 using wildcard pattern matching
    bool wildcardMatching(string &S1, string &S2) {
        int n = S1.size();
        int m = S2.size();

        // Create a DP table to memoize results
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
    }

    bool isMatch(string s, string p) {
        return wildcardMatching(p, s);
    }
};