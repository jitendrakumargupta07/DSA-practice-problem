class Solution {
public:
    int minJumps(vector<int>& nums) 
    {
        int n = nums.size();

        if (n == 1)
            return 0;

        int limit = *max_element(nums.begin(), nums.end());

        vector<int> smallest(limit + 1);

        for (int i = 0; i <= limit; i++)
            smallest[i] = i;

        for (int i = 2; i * i <= limit; i++)
        {
            if (smallest[i] == i)
            {
                for (int j = i * i; j <= limit; j += i)
                {
                    if (smallest[j] == j)
                        smallest[j] = i;
                }
            }
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            int val = nums[i];
            unordered_set<int> st;

            while (val > 1)
            {
                int factor = smallest[val];
                st.insert(factor);

                while (val % factor == 0)
                    val /= factor;
            }

            for (auto &x : st)
                mp[x].push_back(i);
        }

        vector<int> vis(n, -1);
        queue<int> qu;

        qu.push(0);
        vis[0] = 0;

        while (!qu.empty())
        {
            int idx = qu.front();
            qu.pop();

            if (idx == n - 1)
                return vis[idx];

            if (idx - 1 >= 0 && vis[idx - 1] == -1)
            {
                vis[idx - 1] = vis[idx] + 1;
                qu.push(idx - 1);
            }

            if (idx + 1 < n && vis[idx + 1] == -1)
            {
                vis[idx + 1] = vis[idx] + 1;
                qu.push(idx + 1);
            }

            int cur = nums[idx];

            if (cur >= 2 && smallest[cur] == cur)
            {
                if (mp.find(cur) != mp.end())
                {
                    for (auto &next : mp[cur])
                    {
                        if (vis[next] == -1)
                        {
                            vis[next] = vis[idx] + 1;
                            qu.push(next);
                        }
                    }

                    mp.erase(cur);
                }
            }
        }

        return -1;
    }
};