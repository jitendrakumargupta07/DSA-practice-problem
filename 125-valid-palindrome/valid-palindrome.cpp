class Solution {
public:
char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        return ch + ('a' - 'A');
    }
}
bool isValidCharacter(char ch){
    if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9')){
        return true;
    }else{
        return false;
    }
}
    bool isPalindrome(string s) {
        int start =0;
        int end = s.length() - 1;
        while(start <= end){
            while(start<end && !isValidCharacter(s[start])){
                start ++;
            }
            while(start < end && !isValidCharacter(s[end])){
                end --;
            }
            if(toLowerCase(s[start]) != toLowerCase(s[end])){
                return false;
            }
            else{
                start ++;
                end --;
            }
        }
        return true;
    }
};