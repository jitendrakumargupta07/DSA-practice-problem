class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.length();
        
        while (i < n && isspace(s[i])) ++i;

        if (i < n && (s[i] == '+' || s[i] == '-')) ++i;

        bool isNumeric = false, hasDot = false, hasExp = false;

        while (i < n) {
            if (isdigit(s[i])) {
                isNumeric = true;
            } else if (s[i] == '.') {
                if (hasDot || hasExp) return false;
                hasDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (hasExp || !isNumeric) return false;
                hasExp = true;
                isNumeric = false;
                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) ++i;
            } else {
                break;
            }
            ++i;
        }

        while (i < n && isspace(s[i])) ++i;

        return isNumeric && i == n;
    }
};