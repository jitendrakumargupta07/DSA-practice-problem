class Solution {
public:
    char findKthBit(int n, int k) {
        int mid = (1<<(n-1));
        
        if(n == 1) return '0';

        if(mid == k) return '1';

        else if(k < mid) return findKthBit(n-1, k);
        
        else return findKthBit(n - 1, (1 << n) - k) == '0' ? '1' : '0';
    }
};
