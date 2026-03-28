/*
 * Problem  : 820. Find Eventual Safe States
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * URL      : https://leetcode.com/problems/find-eventual-safe-states/
 */

class Solution {
    bool detectCycle(int i, vector<int> adjList[], vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[i]=1;
        pathVis[i]=1;

        for(auto it: adjList[i]){
            if(!vis[it]){
                if(detectCycle(it,adjList,vis,pathVis,check)){
                    return true;
                }
            } else if(pathVis[it]){
                return true;
            }
        }

        check[i]=1;
        pathVis[i]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adjList[n];
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n,0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adjList[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                detectCycle(i,adjList,vis,pathVis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};