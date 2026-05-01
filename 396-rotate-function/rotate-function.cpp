class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int F = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += i*nums[i];
        }

        int ans = F;

        for(int k = 0; k < n; k++) {
            int newF = F + sum - n*nums[n-1-k]; //Very Intutive && Cricucial Part To Think This Formula

            ans = max(ans, newF);

            F = newF; //Update
        }

        return ans;
    }
};