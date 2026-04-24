class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int k = pos.size();

            vector<long long> prefix(k, 0);
            prefix[0] = pos[0];

            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + pos[i];
            }

            for (int j = 0; j < k; j++) {
                long long left = 0, right = 0;

                if (j > 0)
                    left = (long long)j * pos[j] - prefix[j - 1];

                if (j < k - 1)
                    right = (prefix[k - 1] - prefix[j]) - (long long)(k - j - 1) * pos[j];

                ans[pos[j]] = left + right;
            }
        }

        return ans;
    }
};