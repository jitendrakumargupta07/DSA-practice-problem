
class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        int l= 1, r=*max_element(a.begin(), a.end()), ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            long long c=0;
            for(int x : a) c += x/m;
            if  (c>=k) ans = m, l=m+1;
            else r=m-1;
        }
        return ans;
    }
};