class Solution {
public:
    int mod = 1000000007;
    int lookup[1001][1001];

    int findPalindromicSubseq(string &str, int leftBound, int rightBound) {
        if (leftBound > rightBound) return 0;
        if (leftBound == rightBound) return 1;

        if (lookup[leftBound][rightBound] != -1) {
            return lookup[leftBound][rightBound];
        }

        long long result = 0;

        if (str[leftBound] == str[rightBound]) {
            int forward = leftBound + 1;
            int backward = rightBound - 1;

            while (forward <= backward && str[forward] != str[leftBound]) forward++;
            while (forward <= backward && str[backward] != str[rightBound]) backward--;

            if (forward < backward) {
                result = 2 * findPalindromicSubseq(str, leftBound + 1, rightBound - 1) -
                         findPalindromicSubseq(str, forward + 1, backward - 1);
            } else if (forward == backward) {
                result = 2 * findPalindromicSubseq(str, leftBound + 1, rightBound - 1) + 1;
            } else {
                result = 2 * findPalindromicSubseq(str, leftBound + 1, rightBound - 1) + 2;
            }
        } else {
            result = findPalindromicSubseq(str, leftBound + 1, rightBound) +
                     findPalindromicSubseq(str, leftBound, rightBound - 1) -
                     findPalindromicSubseq(str, leftBound + 1, rightBound - 1);
        }

        if (result < 0) result += mod;
        return lookup[leftBound][rightBound] = result % mod;
    }

    int countPalindromicSubsequences(string input) {
        memset(lookup, -1, sizeof(lookup));
        return findPalindromicSubseq(input, 0, input.size() - 1);
    }
};