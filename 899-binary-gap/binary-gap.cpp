class Solution {
public:
    int binaryGap(int n) {
        int pre = -1, curr = 0, max_val = 0;
        while ( n > 0) {
            if ( (n & 1) && pre == -1){
                pre = curr;
            }
            else if ( n & 1){
                max_val = max(max_val, curr - pre);
                pre = curr;
            }
            curr++;
            n = n >> 1;
        }
        return max_val;
    }
};