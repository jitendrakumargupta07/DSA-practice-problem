class Solution {
private:
    void dfs(unordered_map<string, int> &mpp, vector<vector<string>> &ans, vector<string> &temp, string word, string beginWord) {
        if (word == beginWord) {
            temp.push_back(word);
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            temp.pop_back();
        }
        int level = mpp[word];
        temp.push_back(word);
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == original) continue;
                string next = word;
                next[i] = ch;
                if (mpp.find(next) != mpp.end() && mpp[next] == level - 1) {
                    dfs(mpp, ans, temp, next, beginWord);
                }
            }
        }

        temp.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int> mpp;

        if (!wordSet.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int level = mpp[word];

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == original) continue;
                    string next = word;
                    next[i] = ch;

                    if (wordSet.count(next) && mpp.find(next) == mpp.end()) {
                        mpp[next] = level + 1;
                        q.push(next);
                    }
                }
            }
        }

        if (!mpp.count(endWord)) return {};

        vector<vector<string>> ans;
        vector<string> temp;
        dfs(mpp, ans, temp, endWord, beginWord);
        return ans;
    }
};