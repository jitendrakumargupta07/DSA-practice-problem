class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int j=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(j<i+1)j=i+1;
            while(j<n && nums[j]<=2*nums[i]) j++;
            ans+=j-i-1;
        }
        return ans;
    }
};