#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7; 
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll ans = 0, cur = 0; // Use long long to avoid overflow
        for(int i = 0;i < nums.size();i++) {
            // use a temperary variable to store the contribution of nums[i] as the maximum number
            ll now = ((ll)nums[i] * nums[i] % mod * cur % mod + (ll)nums[i] * nums[i] % mod * nums[i]) % mod;
            ans = (ans + now) % mod;
            cur = (cur * 2 + nums[i]) % mod;
        }
        return (int)ans;
    }
};