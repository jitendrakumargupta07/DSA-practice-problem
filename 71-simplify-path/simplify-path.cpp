class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();

        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') continue;

            string temp;
            while (i < n && path[i] != '/') {
                temp += path[i];
                ++i;
            }

            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(temp);
            }
        }

        // Now build the simplified path
        vector<string> dirs;
        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string result;
        for (const string& dir : dirs) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};