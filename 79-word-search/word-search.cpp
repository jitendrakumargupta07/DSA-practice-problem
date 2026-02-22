class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index])
            return false;

        if (index == word.length() - 1)
            return true;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = dfs(board, word, index + 1, row + 1, col) ||
                     dfs(board, word, index + 1, row - 1, col) ||
                     dfs(board, word, index + 1, row, col + 1) ||
                     dfs(board, word, index + 1, row, col - 1);

        board[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};