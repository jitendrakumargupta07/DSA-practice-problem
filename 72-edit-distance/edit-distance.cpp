class Solution {
public:
    int UsingTabulationSO(string &a, string &b){
        int ans = 0;
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);

        for(int row = a.length();row>=0;row--){
            next[row] = a.length()-row;
        }

        for(int col = b.length()-1;col>=0;col--){ 
            // most imp line
            curr[a.length()] = b.length()-col;
            for(int row = a.length()-1;row>=0;row--){
                if(a[row] == b[col]){
                    ans = 0 + next[row+1];
                }
                else{
                    int replace = 1 + next[row+1];
                    int insert = 1 + next[row];
                    int remove = 1 + curr[row+1];
                    ans = min(replace,min(insert,remove));
                }
                curr[row] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int ans = UsingTabulationSO(word1,word2);
        return ans;
    }
};