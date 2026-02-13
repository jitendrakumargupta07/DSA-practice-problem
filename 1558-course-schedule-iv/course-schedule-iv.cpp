class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses) ; 
        vector<int>indegree(numCourses) ;
        for(auto edge : prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++ ;
        }

        queue<int>q;
        for(int i=0 ; i<indegree.size() ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<unordered_set<int>>ancestors(numCourses) ;
        while(q.empty() == false)
        {
            int val = q.front();
            q.pop();
            for(auto node : adj[val])
            {
                ancestors[node].insert(ancestors[val].begin() , ancestors[val].end());
                ancestors[node].insert(val) ;
   
                indegree[node]--;
                if(indegree[node] == 0)
                {
                    q.push(node);
                }
            }
        }

        vector<bool> ans;
        for(auto edge : queries)
        {
            int parent = edge[0] ;
            int child = edge[1] ;
            if(ancestors[child].count(parent) > 0)
            {
                ans.push_back(true);
            }
            else{
                ans.push_back(false) ;
            }
        }

        return ans;
    }

};