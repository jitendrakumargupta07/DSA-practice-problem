class NumArray {
    int n;
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        sum = vector<int>(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? sum[right] : sum[right] - sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */