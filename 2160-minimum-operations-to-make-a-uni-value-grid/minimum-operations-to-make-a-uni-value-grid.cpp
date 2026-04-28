class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        
        // Step 1: Flatten the grid into a single array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        
        // Step 2: Check if transformation is possible
        int remainder = nums[0] % x;
        for (int num : nums) {
            if (num % x != remainder) return -1;  // Impossible to make them equal
        }
        
        // Step 3: Find the median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        // Step 4: Count the minimum operations to make all elements equal to median
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};