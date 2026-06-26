class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long ans = 0;
        vector<int> st;
        for (int x : nums) {
            if (x == 0) {
                ans += (int)st.size();
                st.clear();
                continue;
            }

            while (!st.empty() && st.back() > x) {
                st.pop_back();
                ans += 1;
            }

            if (st.empty() || st.back() < x) {
                st.push_back(x);
            }
        }

        ans += (int)st.size();

        return (int)ans;
    }
};