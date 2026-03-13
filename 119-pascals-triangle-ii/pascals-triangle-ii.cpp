class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for(int i=1; i<=rowIndex; i++){
            ans[i] = int((ans[i-1] * (rowIndex-i+1ll)) / i);     //1ll converst 1 to long 1
        }  
        return ans;
    }
};