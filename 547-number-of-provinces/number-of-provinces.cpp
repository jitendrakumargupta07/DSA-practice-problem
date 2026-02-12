class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int i = 0; i < n; ++i) {
                if (isConnected[node][i] == 1 && !visited[i]) {
                    dfs(i);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                provinces++;
            }
        }

        return provinces;
    }
};