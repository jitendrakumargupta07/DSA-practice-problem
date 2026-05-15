class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size()-1;

        for(int i=size;i>0;i--){
            if(nums[i]<nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};