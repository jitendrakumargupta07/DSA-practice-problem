class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        for (const auto& interval : intervals) {
            // Case 1: Non-overlapping, current interval is before newInterval
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            }
            // Case 2: Non-overlapping, current interval is after newInterval
            else if (interval[0] > newInterval[1]) {
                result.push_back(newInterval); // Add merged interval
                newInterval = interval;       // Update newInterval to the current one
            }
            // Case 3: Overlapping intervals
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        // Add the final merged interval
        result.push_back(newInterval);

        return result;
    }
};