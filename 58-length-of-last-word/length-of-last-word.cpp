class Solution {
public:
    int lengthOfLastWord(string s) {
        int llw = 0;
        bool word = false;
        int wordstart = s.size() - 1;
        
        // Skip trailing spaces
        while(wordstart >= 0 && s[wordstart] == ' '){
            wordstart--;
        }
        
        // Find the last word
        int temp = wordstart;
        while(wordstart >= 0 && s[wordstart] != ' '){
            wordstart--;
        }
        
        // Return length of last word
        return temp - wordstart;
    }
};