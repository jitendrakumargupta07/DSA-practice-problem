class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size(), pos = 0;

        while(pos < min(m,n)/2){
            vector<int> temp;
            int k_temp = k % (2 * ((m-2*pos) + (n-2*pos)) - 4);

            for(int i = pos; i < n - pos; i++)
                temp.push_back(grid[pos][i]);

            for(int i = pos+1; i < m - pos; i++)
                temp.push_back(grid[i][n-pos-1]);

            for(int i = n - pos - 2; i >= pos; i--)
                temp.push_back(grid[m-pos-1][i]);
            
            for(int i = m - pos - 2; i > pos; i--)
                temp.push_back(grid[i][pos]);

            // Assingn value
            for(int i = pos; i < n - pos; i++)
                grid[pos][i] = temp[k_temp++ % temp.size()];

            for(int i = pos+1; i < m - pos; i++)
                grid[i][n-pos-1] = temp[k_temp++ % temp.size()];

            for(int i = n - pos - 2; i >= pos; i--)
                grid[m-pos-1][i] = temp[k_temp++ % temp.size()];
            
            for(int i = m - pos - 2; i > pos; i--)
                grid[i][pos] = temp[k_temp++ % temp.size()];

            pos++;
        }
        return grid;
    }
};
