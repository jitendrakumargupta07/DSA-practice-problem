class Solution {
public:
    void generate(vector<vector<int>>&ans, vector<int>&nums, vector<int>&curr, int idx, int sum){
        if(sum == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == nums.size())return;
        for(int i = idx; i<nums.size();i++){
            if(i > idx && nums[i] == nums[i-1])continue;
            if(nums[i] > sum)break;
            curr.push_back(nums[i]);
            generate(ans,nums,curr,i+1,sum -nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        generate(ans,nums,curr,0,k);
        return ans;
    }
};