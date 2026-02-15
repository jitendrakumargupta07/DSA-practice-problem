class Solution {
public:
  int totalNQueens(int n) {
    // given n , return the number of distinct solutions to the n-queens puzzle.
    if (n == 1) {
      return 1;
    }

    // Initialize data structures
    vector<vector<string>> results;
    vector<string> board(n, string(n, '.')); // Initialize an empty board
    vector<bool> cols(n, false);             // Track columns with queens
    vector<bool> diag1(2 * n - 1, false);    // Track \ diagonals
    vector<bool> diag2(2 * n - 1, false);    // Track / diagonals

    // Call backtracking function to find solutions
    backtrack(0, n, board, results, cols, diag1, diag2);

    // Return the number of distinct solutions
    return results.size();
  }

private:
  void backtrack(int row, int n, vector<string>& board,
                 vector<vector<string>>& results, vector<bool>& cols,
                 vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
      results.push_back(board); // Found a valid configuration
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
        continue; // Conflict detected, skip this position
      }

      // Place the queen
      board[row][col] = 'Q';
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

      // Recurse for the next row
      backtrack(row + 1, n, board, results, cols, diag1, diag2);

      // Backtrack: Remove the queen
      board[row][col] = '.';
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
  }
};