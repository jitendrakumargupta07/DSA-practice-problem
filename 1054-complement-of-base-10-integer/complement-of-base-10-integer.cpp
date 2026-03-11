class Solution {
public:
    int bitwiseComplement(int n) {
        // Special case for 0 as its complement is 1
        if (n == 0) return 1;

        unsigned int mask = 0;
        int temp = n;

        // Create a mask of 1s with the same length as n's binary representation
        // e.g., if n = 5 (101), mask becomes 7 (111)
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        // XORing n with the mask flips all bits of n within that range
        return n ^ mask;
    }
};