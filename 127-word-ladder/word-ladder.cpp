class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string, int>> q; // {current word, transformation count}
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();

            if (currentWord == endWord) return level;

            // Try all possible one-character transformations
            for (int i = 0; i < currentWord.size(); i++) {
                string tempWord = currentWord;

                for (char c = 'a'; c <= 'z'; c++) {
                    tempWord[i] = c;
                    if (wordSet.find(tempWord) != wordSet.end()) {
                        q.push({tempWord, level + 1});
                        wordSet.erase(tempWord); // Avoid revisiting
                    }
                }
            }
        }
        return 0; // If no transformation sequence is found
    }
};