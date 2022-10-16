class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courseDependency(numCourses);
        vector<int> degree(numCourses, 0);\
        queue<int> courseQueue;
        vector<int> courseOrder;
        for(auto p: prerequisites) {
            courseDependency[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        for(int i=0; i<numCourses; i++) 
            if(degree[i] == 0)  courseQueue.push(i);
        while(!courseQueue.empty()) {
            int courseIndex = courseQueue.front();
            courseOrder.push_back(courseIndex);
            courseQueue.pop();
            for(auto c: courseDependency[courseIndex]) 
                if(--degree[c] == 0)   courseQueue.push(c);             
        }
        if (courseOrder.size() < numCourses ) courseOrder = {};
        return courseOrder;
    }
};