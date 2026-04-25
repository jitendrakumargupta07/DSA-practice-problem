class Solution {
public:

    long long getPos(int side, int x, int y) {

        if (x == 0) return y;

        if (y == side) return side + x;

        if (x == side) return 3LL * side - y;

        return 4LL * side - x;
    }

    bool can(vector<long long>& pos, int k, long long d, long long per) {

        int n = pos.size();

        vector<long long> arr = pos;

        for (auto x : pos)
            arr.push_back(x + per);

        int m = arr.size();

        vector<int> next(m);

        int j = 0;

        for (int i = 0; i < m; i++) {

            while (j < m && arr[j] - arr[i] < d)
                j++;

            next[i] = j;
        }

        for (int start = 0; start < n; start++) {

            int cur = start;

            int cnt = 1;

            while (cnt < k) {

                cur = next[cur];

                if (cur >= start + n)
                    break;

                cnt++;
            }

            if (cnt == k) {

                long long lastGap = per - (arr[cur] - arr[start]);

                if (lastGap >= d)
                    return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {

        vector<long long> pos;

        for (auto &p : points) {

            pos.push_back(getPos(side, p[0], p[1]));
        }

        sort(pos.begin(), pos.end());

        long long per = 4LL * side;

        long long low = 0;
        long long high = 2LL * side;

        long long ans = 0;

        while (low <= high) {

            long long mid = (low + high) / 2;

            if (can(pos, k, mid, per)) {

                ans = mid;
                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        return ans;
    }
};