class Solution {
public:
    int minJumps(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor sieve
        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;

        for (int i = 2; i * i <= mx; i++) 
        {
            if (spf[i] == i) 
            {
                for (int j = i * i; j <= mx; j += i) 
                {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> bucket;

        for (int i = 0; i < n; i++) 
        {
            int x = nums[i];
            unordered_set<int> primes;

            while (x > 1) 
            {
                int p = spf[x];
                primes.insert(p);
                while (x % p == 0) x /= p;
            }

            for (int p : primes) 
            {
                bucket[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) 
        {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) return d;

            // Adjacent moves
            if (i - 1 >= 0 && dist[i - 1] == -1) 
            {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) 
            {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // Prime teleportation
            int val = nums[i];

            if (val >= 2 && spf[val] == val) 
            {
                int p = val;

                if (bucket.count(p)) {
                    for (int nxt : bucket[p]) 
                    {
                        if (dist[nxt] == -1) 
                        {
                            dist[nxt] = d + 1;
                            q.push(nxt);
                        }
                    }

                    bucket.erase(p);
                }
            }
        }

        return -1;
    }
};