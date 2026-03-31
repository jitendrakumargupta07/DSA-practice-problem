class Solution {
public:
    bool matches(const string& ans, int start, const string& str2) {
        for (int j = 0; j < str2.size(); j++) {
            if (ans[start + j] != str2[j]) return false;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int L = n + m - 1;

        string ans(L, '?');
        vector<bool> fixed(L, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;
                    if (ans[pos] != '?' && ans[pos] != str2[j]) {
                        return "";
                    }
                    ans[pos] = str2[j];
                    fixed[pos] = true;
                }
            }
        }

        for (int i = 0; i < L; i++) {
            if (ans[i] == '?') ans[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (matches(ans, i, str2)) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;
                        if (!fixed[pos]) {
                            ans[pos] = (str2[j] == 'a' ? 'b' : 'a');
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return "";
                }
            }
        }

        for (int i = 0; i < n; i++) {
            bool eq = matches(ans, i, str2);
            if (str1[i] == 'T' && !eq) return "";
            if (str1[i] == 'F' && eq) return "";
        }

        return ans;
    }
};