class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if (n - k + 1 < (1 << k)) return false;
        
        vector<bool> seen(1 << k, false);
        int mask = (1 << k) - 1;
        int curr = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            curr = ((curr << 1) & mask) | (s[i] - '0');
            
            if (i >= k - 1) {
                if (!seen[curr]) {
                    seen[curr] = true;
                    count++;
                    
                    if (count == (1 << k))
                        return true;
                }
            }
        }
        
        return false;
    }
};