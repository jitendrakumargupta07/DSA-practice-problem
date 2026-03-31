class Solution {
public:
    bool ispal(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    int helper(int i, int n, string s, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = INT_MAX;

        for(int j = i;j<n;j++){
            if(ispal(i,j,s)){
                int cost = 1 + helper(j+1,n, s,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut1(string s) {
        int n = s.length();
        vector<int> dp(n,-1);

        return helper(0,n,s,dp)-1;
    }

    int minCut2(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0;i--){
            int mini = INT_MAX;

            for(int j = i;j<n;j++){
                if(ispal(i,j,s)){
                int cost = 1 + dp[j+1];
                mini = min(mini,cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }

    int minCut(string s) {
        int n = s.size();

        // Precompute palindrome table
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) pal[i][j] = true; 
                    else pal[i][j] = pal[i+1][j-1];
                }
            }
        }

        // dp[i] = min cuts needed for substring s[i..n-1]
        vector<int> dp(n+1, 0);
        dp[n] = 0;  // base: empty string

        for (int i = n-1; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                if (pal[i][j]) {
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1; // subtract 1 because no cut needed for whole palindrome
    }

};