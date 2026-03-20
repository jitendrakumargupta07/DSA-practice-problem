class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> colX(m, 0), colY(m, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X')
                    colX[j]++;
                else if (grid[i][j] == 'Y')
                    colY[j]++;

                x += colX[j];
                y += colY[j];

                if (x == y && x > 0)
                    cnt++;
            }
        }
        return cnt;
    }
};