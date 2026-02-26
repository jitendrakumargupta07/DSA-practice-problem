class Solution {
public:
    int numSteps(string s) {
        int step = 0, carry = 0;
        int n = size(s);
        for(int i = n - 1; i > 0; i--) {
            int currval = (s[i] - '0') + carry;
            if(currval == 1) {
                step+=2;
                carry = 1;
            } else {
                step+=1;
                carry = (currval == 2) ? 1 : 0;
            }
        }
        return step+carry;
    }
};