#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        // Prefix sums for each column: prefix[j][i+1] = sum of grid[0..i][j]
        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];
            }
        }
        
        // DP arrays: prevPick[i] — max score ending with picking up to row i in previous column
        //           prevSkip[i] — max score if we skipped picking in previous column up to row i
        vector<long long> prevPick(n + 1, 0);
        vector<long long> prevSkip(n + 1, 0);
        
        // Iterate through columns starting from the second one (j = 1)
        for (int j = 1; j < n; ++j) {
            vector<long long> currPick(n + 1, 0);
            vector<long long> currSkip(n + 1, 0);
            
            // Consider all combinations of previous and current selections
            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        // We can take from current column starting after prev
                        long long score = prefix[j - 1][curr] - prefix[j - 1][prev];
                        currPick[curr] = max(currPick[curr], prevSkip[prev] + score);
                        currSkip[curr] = max(currSkip[curr], prevSkip[prev] + score);
                    } else {
                        // curr <= prev: we take from the current column up to curr
                        long long score = prefix[j][prev] - prefix[j][curr];
                        currPick[curr] = max(currPick[curr], prevPick[prev] + score);
                        currSkip[curr] = max(currSkip[curr], prevPick[prev]);
                    }
                }
            }
            
            // Update previous arrays for the next iteration
            prevPick = std::move(currPick);
            prevSkip = std::move(currSkip);
        }
        
        // The answer is the maximum value in prevPick
        return *max_element(prevPick.begin(), prevPick.end());
    }
};