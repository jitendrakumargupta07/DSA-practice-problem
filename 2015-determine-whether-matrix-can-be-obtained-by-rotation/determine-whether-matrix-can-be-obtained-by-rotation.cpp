class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int temp;

        if(mat == target) return true;

        for(int r = 0; r < 3; r++) {
            for(int i = 0; i < n; i++ ) {
                for(int j = i+1; j < n; j++) {
                    temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
            
            for(int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }

            if(mat == target) return true;
        }
        
        return false;
    }
};