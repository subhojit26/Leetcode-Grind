/*
 * Problem  : 207. Course Schedule
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * URL      : https://leetcode.com/problems/course-schedule/
 */

class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)){
                    return true;
                }
                }else if(pathVis[it]){
                    return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> adj[numCourses];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
        }
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};