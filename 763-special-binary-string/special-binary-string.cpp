class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";
        
        vector<string> parts;
        int balance = 0, start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            balance += (s[i] == '1' ? 1 : -1);
            if (balance == 0) {
                parts.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }
        
        sort(parts.rbegin(), parts.rend()); // Sort in lexicographically descending order
        
        string result = "";
        for (const string &part : parts) {
            result += part;
        }
        
        return result;
    }
};