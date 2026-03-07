class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        int countS0 = 0; // Pattern: 010101...
        int countS1 = 0; // Pattern: 101010...
        int minCount = n;

        int l = 0;

        for (int r = 0; r < s.size(); r++) {

            if (s[r] != (r % 2 ? '1' : '0')) countS0++;
            if (s[r] != (r % 2 ? '0' : '1')) countS1++;

            if (r - l + 1 > n) {

                if (s[l] != (l % 2 ? '1' : '0')) countS0--;
                if (s[l] != (l % 2 ? '0' : '1')) countS1--;

                l++;
            }

            if (r - l + 1 == n) {
                minCount = min({minCount, countS0, countS1});
            }
        }

        return minCount;
    }
};