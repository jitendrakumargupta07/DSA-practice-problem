class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(32, 0);
        fib[0] = 1;
        fib[1] = 2;
        
        for (int i = 2; i < 32; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        int prev_bit = 0;
        int result = 0;
        
        for (int i = 30; i >= 0; --i) {
            if (n & (1 << i)) {
                result += fib[i];
                if (prev_bit == 1) {
                    return result;
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }
        
        return result + 1;
    }
};