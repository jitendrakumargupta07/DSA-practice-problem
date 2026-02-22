class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curCombination, int i,
                   int n, int k) {
        if (curCombination.size() == k) {
            res.emplace_back(curCombination);
            return;
        }
        if (i == n) {
            return;
        }
        curCombination.push_back(i + 1);
        backtrack(res, curCombination, i + 1, n, k);
        curCombination.pop_back();
        backtrack(res, curCombination, i + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curCombination;
        backtrack(res, curCombination, 0, n, k);
        return res;
    }
};