class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for (int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isValid(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    bool isValid(vector<int>& weights, int days, int mid) {
        int sum = 0, count = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > mid) {
                count++;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }
        return count <= days;
    }
};