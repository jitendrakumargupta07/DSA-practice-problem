// class Solution {
// public:
//     bool isPalindrome(int x) {
//     if(x < 0) return false;
//     int temp = x; 
//     long rev = 0;
//     while(temp > 0){
//         rev = rev*10 + (long)temp%10;
//         temp /= 10;
//     }
//     return rev == x;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        int dup=x;
        long long revn=0;
        while(x>0){
            int ld= x%10;
            revn= ((revn*10)+ld);
            x=x/10;
        }
        if (dup==revn){
            return true;
            }else{
            return false;
        }
    }
};