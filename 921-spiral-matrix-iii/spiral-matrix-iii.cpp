class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        ans.push_back({rs, cs});
        int steps = 0;
        int i = 0;
        while (ans.size() < rows * cols) {
            if (i == 0 || i == 2)
                steps++;
            for (int cnt = 0; cnt < steps; cnt++) {
                rs += dir[i][0] ;
                cs += dir[i][1] ;
                if (rs < rows && cs < cols && rs >= 0 && cs >= 0) {
                    ans.push_back({rs, cs});
                }
            }

            i = (i + 1) % 4;
        }
        return ans;
    }
};