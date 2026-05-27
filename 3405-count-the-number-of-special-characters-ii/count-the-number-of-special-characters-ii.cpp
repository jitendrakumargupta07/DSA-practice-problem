class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> arr(52, -1);

        for(int i = 0; i < word.length(); i++)
        {
            if(word[i] >= 65 && word[i] <= 90)
            {
                // lowercase present
                if(arr[word[i] - 'A' + 26] == 1)
                {
                    arr[word[i] - 'A'] = 1;
                }
                // lowercase absent therefore uppercase neglected
                else {
                    arr[word[i] - 'A'] = -2;
                }
            }
            else
            {
                // uppercase absent
                if(arr[word[i] - 'a'] == -1)
                {
                    arr[word[i] - 'a' + 26] = 1;
                }
                // uppercase present
                else
                {
                    arr[word[i] - 'a' + 26] = -2;
                }
            }
        }

        int ans = 0;
        int left = 0, right = 26;

        while(right < 52)
        {
            if(arr[left] == 1 && arr[right] == 1)
            {
                ans++;
            }
            left++;
            right++;
        }

        return ans;
    }
};