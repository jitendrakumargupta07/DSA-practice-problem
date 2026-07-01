class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int rowMax = -1, colMax = -1;

                for(int c = 0; c < n; c++){
                    colMax = max(colMax, grid[i][c]);
                }

                for(int r = 0; r < n; r++){
                    rowMax = max(rowMax, grid[r][j]);
                }

                ans += (min(rowMax, colMax) - grid[i][j]);
            }
        }
        return ans;
    }
};