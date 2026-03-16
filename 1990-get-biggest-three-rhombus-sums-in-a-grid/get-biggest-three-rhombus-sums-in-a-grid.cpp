class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // area 0 rhombus (single cell)
                st.insert(grid[i][j]);

                for(int k = 1; ; k++) {

                    int bottom = i + 2*k;
                    int left = j - k;
                    int right = j + k;

                    if(bottom >= m || left < 0 || right >= n)
                        break;

                    int sum = 0;

                    // top -> right
                    for(int t = 0; t < k; t++)
                        sum += grid[i + t][j + t];

                    // right -> bottom
                    for(int t = 0; t < k; t++)
                        sum += grid[i + k + t][j + k - t];

                    // bottom -> left
                    for(int t = 0; t < k; t++)
                        sum += grid[i + 2*k - t][j - t];

                    // left -> top
                    for(int t = 0; t < k; t++)
                        sum += grid[i + k - t][j - k + t];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};