class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) 
    {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) 
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) 
    {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

class Solution {
public:
    bool can(int n, vector<vector<int>>& edges, int k, int mid) 
    {
        DSU dsu(n);
        int upgrades = 0, used = 0;

        for (auto &e : edges) 
        {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) 
            {
                if (s < mid) return false;
                if (!dsu.unite(u, v)) return false;
                used++;
            }
        }

        vector<array<int,3>> normal, upgrade;
        for (auto &e : edges) 
        {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) continue;

            if (s >= mid)
                normal.push_back({u,v,s});
            else if (s*2 >= mid)
                upgrade.push_back({u,v,s});
        }

        for (auto &e : normal) 
        {
            if (dsu.unite(e[0], e[1])) used++;
        }

        for (auto &e : upgrade) 
        {
            if (used == n-1) break;
            if (dsu.unite(e[0], e[1])) 
            {
                upgrades++;
                used++;
                if (upgrades > k) return false;
            }
        }

        return used == n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) 
    {
        int lo = 0, hi = 200000, ans = -1;

        while (lo <= hi) 
        {
            int mid = (lo + hi) / 2;
            if (can(n, edges, k, mid)) 
            {
                ans = mid;
                lo = mid + 1;
            } 
            else 
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};