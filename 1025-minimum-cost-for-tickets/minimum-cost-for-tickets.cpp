class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        unordered_set<int> travelDays(days.begin(), days.end());
    int lastDay = days[n - 1];
    
    // DP array to store the minimum cost up to day i
    vector<int> dp(lastDay + 1, 0);
    
    for (int i = 1; i <= lastDay; i++) {
        if (travelDays.find(i) == travelDays.end()) {
            dp[i] = dp[i - 1]; // No travel on this day
        } else {
            dp[i] = min({
                dp[max(0, i - 1)] + costs[0],  // 1-day pass
                dp[max(0, i - 7)] + costs[1], // 7-day pass
                dp[max(0, i - 30)] + costs[2] // 30-day pass
            });
        }
    }
    
    return dp[lastDay];
    }
};