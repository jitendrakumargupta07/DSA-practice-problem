// using BFS
class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        // store indices of same values
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int jumps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int index = q.front();
                q.pop();

                // reached destination
                if(index == n - 1)
                    return jumps;

                // forward jump
                if(index + 1 < n && !vis[index + 1]) {
                    vis[index + 1] = true;
                    q.push(index + 1);
                }

                // backward jump
                if(index - 1 >= 0 && !vis[index - 1]) {
                    vis[index - 1] = true;
                    q.push(index - 1);
                }

                // same value jump
                for(auto nextIndex : mp[arr[index]]) {
                    if(!vis[nextIndex]) {
                        vis[nextIndex] = true;
                        q.push(nextIndex);
                    }
                }

                // optimization
                mp[arr[index]].clear();
            }

            jumps++;
        }

        return -1;
    }
};