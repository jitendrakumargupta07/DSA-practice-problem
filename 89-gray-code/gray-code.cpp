class Solution {
public:

    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        else{
            vector<int>v=grayCode(n-1);
            vector<int>ans;
            for(auto x=v.begin();x!=v.end();++x){
                ans.push_back(*x);
            }
            for(auto x=v.rbegin();x!=v.rend();++x){
                ans.push_back(*x + (1<<(n-1)));
            }
            return ans;
        }
    }
};