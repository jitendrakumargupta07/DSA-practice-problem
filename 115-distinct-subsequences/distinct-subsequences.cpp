class Solution {
public:
  int numDistinct(string s, string t) {
    // given string s, find subsequences of s equal to t
    // return their number
    // create all possible subsequences of s
    // compare them with t, increase counter if equal
    // return counter
    int m = s.size();
    int n = t.size();
const int MOD = 1e9 + 7;
    // dp[i][j] will store the number of distinct subsequences of s[0..i-1]
    // equal to t[0..j-1]
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

    // Initialize dp[i][0] to 1 because an empty t is a subsequence of any s
    for (int i = 0; i <= m; ++i) {
      dp[i][0] = 1;
    }

    // Fill the dp table
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // If the characters match, we have two choices:
        // 1. Include the current character of s in the subsequence
        // 2. Do not include it
        if (s[i - 1] == t[j - 1]) {
          
dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    // The result is stored in dp[m][n]
    return dp[m][n];
  }
};