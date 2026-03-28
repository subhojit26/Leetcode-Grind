/*
 * Problem  : 210. Course Schedule II
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * URL      : https://leetcode.com/problems/course-schedule-ii/
 */

class Solution {
public:
    bool cycleDetected(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(cycleDetected(it,vis,pathVis,adj)){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
                if(cycleDetected(i,vis,pathVis,adj)){
                    return {};
                }
            }
        }
        stack<int> st;
        vector<int> ans;
        vector<int> vis1(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis1[i]){
                dfs(i,vis1,adj,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};