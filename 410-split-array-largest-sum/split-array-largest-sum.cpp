class Solution {
public:
    bool canSplit(vector<int>& nums, int m, long long mid){
        long long sum=0;
        int count=1;
        for(int x:nums){
            if(sum+x>mid){
                count++;
                sum=x;
                if(count>m)return false;
            }else sum+=x;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long left=*max_element(nums.begin(), nums.end());
        long long right=accumulate(nums.begin(), nums.end(), 0LL);
        while(left<right){
            long long mid=left+(right-left)/2;
            if(canSplit(nums, k, mid))right=mid;
            else left=mid+1;
        }
        return left;
    }
};