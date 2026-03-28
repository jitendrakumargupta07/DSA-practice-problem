class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string str = "";
        for(int i=0;i<n;++i){
            str+='0';
        }
        char c = 'a';
        for(int i = 0; i< n; ++i){
            //invalid
            if(lcp[i][i]!=n-i){
                return "";
            }
            //find all characters started with word[i]
            //If word[j]==word[i], lcp[i][j]!=0
            //Otherwise, str[i] is already settled
            if(str[i]=='0'){
                if(c>'z'){
                    return "";
                }
                str[i] = c;
                c++;
            }
            for(int j=i; j< n; ++j){
                //invalid case
                if(lcp[i][j]!=lcp[j][i]||lcp[i][j]>(n-j)){
                    return "";
                }
                if(i>0&&j>0&& lcp[i-1][j-1]>0 &&lcp[i][j]!=lcp[i-1][j-1]-1){
                    return "";
                }
                //not match
                if(lcp[i][j]==0){
                    continue;
                }
                str[j] = str[i];
            }
        }
        for(int i = 0; i< n; ++i){
            for(int j = i; j<n; ++j){
                if(lcp[i][j]!=0&&str[i]!=str[j])return "";
                if(lcp[i][j]==0&&str[i]==str[j])return "";
            }
        }
        return str;
    }
};