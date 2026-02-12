class Solution {
public:
    bool ok(unordered_map<char, int>& mp) {
        int val = -1, cnt = 0;
        for (auto x : mp) {
            if (x.second != val) {
                val = x.second;
                cnt++;
            }
        }
        return cnt == 1;
    }

    int longestBalanced(string s) {
        int n = s.size(), i, j, ans = 0;
        for (i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (j = i; j < n; j++) {
                mp[s[j]]++;
                if (ok(mp))
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};