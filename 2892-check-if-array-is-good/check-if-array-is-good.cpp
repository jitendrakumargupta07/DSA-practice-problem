class Solution {
public:
    bool isGood(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i] != i + 1)
                return false;
        }

        int cnt = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            if ((nums[i] ^ nums[i + 1]) == 0)
                cnt++;
        }

        return cnt == 1;
    }
};