class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        int res=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                if(nums[i]==res){
                    res++;
                }
                else if(nums[i]<res){
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return res;
        
    }
};