class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int t1 = INT_MAX;

        for(int i = 0; i < n; i++) {
            t1 = min(t1, landStartTime[i] + landDuration[i]);
        }
        
        int mini1 = INT_MAX;
        int temp = t1;
        int m = waterStartTime.size();

        for(int i = 0; i < m; i++) {
            if(waterStartTime[i] <= t1) {
                t1 += waterDuration[i];
                mini1 = min(mini1, t1);
                t1 = temp;
            }
            else {
                t1 += (waterStartTime[i] - t1) + waterDuration[i];
                mini1 = min(mini1, t1);
                t1 = temp;
            }
        }

        int mini2 = INT_MAX;
        int t3 = INT_MAX;

        for(int i = 0; i < m; i++) {
            t3 = min(t3, waterStartTime[i] + waterDuration[i]);
        }

        int prev = t3;

        for(int i = 0; i < n; i++) {
            if(landStartTime[i] <= t3) {
                t3 += landDuration[i];
                mini2 = min(mini2, t3);
                t3 = prev;
            }
            else {
                t3 += (landStartTime[i] - t3) + landDuration[i];
                mini2 = min(mini2, t3);
                t3 = prev;
            }
        }

        return min(mini1, mini2);
    }
};