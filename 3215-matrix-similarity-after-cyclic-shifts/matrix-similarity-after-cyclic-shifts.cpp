class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // A cyclic shift of k is equivalent to k % n
        k %= n;
        if (k == 0) return true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // For the row to remain identical after a shift of k,
                // every element must match the element k positions away.
                // This applies to both left and right shifts in a cyclic sense.
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};