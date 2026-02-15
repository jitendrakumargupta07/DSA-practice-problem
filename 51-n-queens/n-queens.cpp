class Solution {
public:
    // Function to check if placing a queen at (row, col) is safe
    bool safe(vector<string>& board, int row, int col){
        int r = row, c = col;

        // check row-left (any queen placed in the same row, previous columns)
        while(c >= 0) 
            if(board[r][c--] == 'Q') return false;

        // check upper-left diagonal
        r = row, c = col;
        while(r >= 0 && c >= 0) 
            if(board[r--][c--] == 'Q') return false;

        // check lower-left diagonal
        r = row, c = col;
        while(r < board.size() && c >= 0) 
            if(board[r++][c--] == 'Q') return false;

        // If no conflict found → position is safe
        return true;
    }

    // Backtracking function to try placing queens column by column
    void func(int col, vector<vector<string>>& ans, vector<string>& board){
        // Base case: if all columns are filled, store the solution
        if(col == board.size()){
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every row for this column
        for(int row = 0; row < board.size(); row++){
            if(safe(board, row, col)){       // check if position is valid
                board[row][col] = 'Q';       // place queen

                func(col+1, ans, board);     // recurse for next column

                board[row][col] = '.';       // backtrack (remove queen)
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;                  // stores all solutions
        vector<string> board(n, string(n, '.'));     // empty board filled with '.'

        func(0, ans, board);                         // start from column 0
        return ans;
    }
};