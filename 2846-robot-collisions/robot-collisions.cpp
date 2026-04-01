class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> stack; 
        vector<bool> destroyed(n, false);

        for (int i : indices) {
            if (directions[i] == 'R') {
                stack.push_back(i);
            } else {
                while (!stack.empty() && healths[i] > 0) {
                    int topIdx = stack.back();
                    
                    if (healths[topIdx] < healths[i]) {
                        healths[topIdx] = 0;
                        destroyed[topIdx] = true;
                        stack.pop_back();
                        healths[i] -= 1;
                    } else if (healths[topIdx] > healths[i]) {
                        healths[i] = 0;
                        destroyed[i] = true;
                        healths[topIdx] -= 1;
                    } else {
                        healths[topIdx] = 0;
                        destroyed[topIdx] = true;
                        stack.pop_back();
                        healths[i] = 0;
                        destroyed[i] = true;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!destroyed[i]) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};