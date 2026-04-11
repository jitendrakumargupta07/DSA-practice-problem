class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>=3){
                vector<int> &vec = mp[nums[i]];
                int siz = vec.size();
                int j = vec[siz-3];
                ans = min(ans,(i-j));
            }
        }
        if(ans == INT_MAX) return -1;
        return 2*ans;
    }
};