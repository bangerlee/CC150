/*
4.7
Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first project). All of a project's dependencies must be built before the project is. Find a build order that will allow the projects to be built. If there is no valid build order, return an error.
SOLUTION
EXAMPLE Input:
projects: a, b, c, d, e, f
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c) Output: f, e, a, b, d, c
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses,0);
        vector<int> res;
        for(auto x:prerequisites){
            adj[x.second].push_back(x.first);
            degree[x.first]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();q.pop();numCourses--;
            for(int next:adj[cur])
                if(--degree[next]==0){ 
                    q.push(next);
                    res.push_back(next);
                }
        }
        if(numCourses==0) return res;
        return vector<int>(0);
    }
};
