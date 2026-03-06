class Solution {
public:
    bool checkOnesSegment(string s) {
        bool szao = false;
        for(char c: s) {
            if(c == '0') {
                szao = true;
            }
            else if(c == '1' && szao){
                return false;
            }
        }
        return true;
    }
};