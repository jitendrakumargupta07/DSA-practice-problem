class Solution {
public:
    int rotatedDigits(int n) {
        if(n == 1) return 0;

        int count = 0, num, rem;

        for(int i = 1; i <= n; i++ ) {

            bool is_valid = true, is_contain = false;
            num = i;

            while(num > 0) {

                rem = num % 10;
                if(rem == 2 || rem == 5 || rem == 6 || rem == 9) {
                    is_contain = true;
                } else if(rem == 3 || rem == 7 || rem == 4) {
                    is_valid = false;
                    break;
                }
                num /= 10;
            }

            if(is_valid && is_contain) count++;
        }
        return count;
    }
};