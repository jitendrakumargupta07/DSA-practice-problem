class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;
        string ans = "";

        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;
            while (i < rows && j < cols) {
                ans += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};