class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty())
        {  
            int s = q.size();
            for(int k = 0; k < s; k++)
            {
                auto p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                ans.push_back(nums[i][j]);
                if(j == 0 && i + 1 < nums.size())
                {
                    q.push({i + 1, j});
                }
                if(j + 1 < nums[i].size())
                {
                    q.push({i, j + 1});
                }
            }
        }

        return ans; 
    }
};