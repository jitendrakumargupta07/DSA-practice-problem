class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m = mat.size();
        if (m == 0) return mat;
        int n = mat[0].size();
            if (m * n != r * c) 
        {
            return mat;
        }
        
        vector<vector<int>> res(r, vector<int>(c));
                for (int k = 0; k < m * n; k++) 
        {
            int i_src = k / n;
            int j_src = k % n;
            
            int i_dst = k / c;
            int j_dst = k % c;
            
            res[i_dst][j_dst] = mat[i_src][j_src];
        }
        
        return res;
    }
};