class Solution {
public:
    vector<int> parent, rank;

    void setData(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }

    void merge(int u, int v){
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;

        if(rank[u] >= rank[v]){
            parent[v] = u;
            if(rank[u] == rank[v]) rank[u]++;   
        } else {
            parent[u] = v;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        setData(n);

        for(auto &it : allowedSwaps){
            merge(it[0], it[1]);
        }

        unordered_map<int, set<pair<int,int>>> mp;

        for(int i = 0; i < n; i++){
            if(source[i] != target[i]){
                mp[source[i]].insert({findPar(i), i});
            }
        }

        for(int i = 0; i < n; i++){
            if(source[i] != target[i]){
                auto it = mp[target[i]].lower_bound({findPar(i), 0});

                if(it != mp[target[i]].end() && it->first == findPar(i)){
                    int par = it->first;
                    int index = it->second;

                    mp[target[i]].erase(it);

                    auto u = mp[source[i]].find({findPar(i), i});
                    if(u != mp[source[i]].end())
                        mp[source[i]].erase(u);

                    swap(source[i], source[index]);

                    if(source[index] != target[index]){
                        mp[source[index]].insert({findPar(index), index});
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(source[i] != target[i]) ans++;
        }
        return ans;
    }
};