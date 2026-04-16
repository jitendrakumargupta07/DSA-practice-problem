class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            int m = vec.size();

            int prev = vec[(pos - 1 + m) % m];
            int next = vec[(pos + 1) % m];

            int d1 = abs(q - prev);
            d1 = min(d1, n - d1);

            int d2 = abs(q - next);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};