class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int cnt = 0;
        int total = n * n;

        int direction = 0;

        int x = 0, y = 0;

        while (cnt < total) {
            matrix[x][y] = ++cnt;

            int new_x = x + dx[direction];
            int new_y = y + dy[direction];

            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n ||
                matrix[new_x][new_y]) {
                direction = (direction + 1) % 4;
            }

            x += dx[direction];
            y += dy[direction];
        }

        return matrix;
    }
};