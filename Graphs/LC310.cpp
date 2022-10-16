class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)    return {0};
        vector<vector<int>> adjList(n);
        vector<int> degree(n,0);
        vector<int> ans;
        queue<int> q;
        for(auto p: edges) {
            adjList[p[0]].push_back(p[1]);
            adjList[p[1]].push_back(p[0]);
            degree[p[0]]++;
            degree[p[1]]++;
        }
        for(int i=0; i<n; i++)
            if(degree[i] == 1)  q.push(i);
        while(n>2) {
            int size = q.size();
            n -= size;
            while(size--) {
                int i = q.front();
                q.pop();
                for(auto a: adjList[i]) 
                    if(--degree[a] == 1)    q.push(a);
            }
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};