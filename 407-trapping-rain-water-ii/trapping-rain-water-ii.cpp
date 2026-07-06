
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j : {0, n - 1}) {
                pq.emplace(heightMap[i][j], i, j);
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    pq.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        vector<int> directions = {-1, 0, 1, 0, -1};

        int trappedWater = 0;

        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + directions[k];
                int ny = y + directions[k + 1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                trappedWater += max(0, height - heightMap[nx][ny]);

                pq.emplace(max(height, heightMap[nx][ny]), nx, ny);
                visited[nx][ny] = true;
            }
        }

        return trappedWater;
    }
};