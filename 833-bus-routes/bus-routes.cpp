class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios_base::sync_with_stdio(0);
        map<int,vector<int>>mp;
        int n = routes.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < routes[i].size(); j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        map<int,int>bus;
        q.push({0,source});
        while(!q.empty()){
            int u = q.front().second,stops = q.front().first; q.pop();
            if(u == target){
                return stops;
            }
            for(auto x : mp[u]){
                if(bus.find(x) == bus.end()){
                    for(auto y : routes[x]){
                        q.push({stops+1,y});
                    }
                    bus[x]++;
                }
            }
        }
        return -1;
    }
};