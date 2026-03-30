class Solution {
public:
  vector<vector<string>> partition(string s) {
    // return all substring of s which are palindromes
        vector<vector<string>> ans;
        vector<string> current;
        partitionHelper(s, 0, current, ans);
        return ans;
    }
    
private:
    void partitionHelper(const string& s, int start, vector<string>& current, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }
        
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                current.push_back(s.substr(start, i - start + 1));
                partitionHelper(s, i + 1, current, ans);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};