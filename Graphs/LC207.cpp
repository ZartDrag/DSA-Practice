class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> degree(numCourses,0);
        for(auto p:prerequisites) {
            adjList[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) 
            if(degree[i] == 0)  q.push(i);
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            numCourses--;
            for(int c: adjList[course]){
                if(--degree[c] == 0)    q.push(c);
            }
        }
        return numCourses == 0;
    }
};