class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0), result;
        vector<vector<int>> adjList(numCourses);
        
        for (auto& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            
            for (int next : adjList[course]) {
                if (--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return result.size() == numCourses ? result : vector<int>();
    }
};