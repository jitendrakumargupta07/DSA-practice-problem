class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        // Directions: up, down, left, right
        vector<vector<vector<int>>> dirs = 
        {
            {}, 
            {{0,-1},{0,1}},       // type 1
            {{-1,0},{1,0}},       // type 2
            {{0,-1},{1,0}},       // type 3
            {{0,1},{1,0}},        // type 4
            {{0,-1},{-1,0}},      // type 5
            {{0,1},{-1,0}}        // type 6
        };

        // Reverse direction check mapping
        auto isConnected = [&](int fromType, int dx, int dy, int toType) 
        {
            for (auto &d : dirs[toType]) 
            {
                if (d[0] == -dx && d[1] == -dy)
                    return true;
            }
            return false;
        };

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) 
        {
            auto [x,y] = q.front();
            q.pop();

            if (x == m-1 && y == n-1)
                return true;

            int type = grid[x][y];

            for (auto &d : dirs[type]) 
            {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) 
                {
                    if (isConnected(type, d[0], d[1], grid[nx][ny])) 
                    {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }
};