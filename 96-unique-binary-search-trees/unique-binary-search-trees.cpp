class Solution {
public:
    int numTrees(int n) {
        vector<int> trees (n + 1, 0);
        trees[0] = 1;

        for (int i = 1; i < n + 1; i++)
            for (int j = 0; j < i; j++)
                trees[i] += trees[j] * trees[i - j - 1];

        return trees[n];
    }
};