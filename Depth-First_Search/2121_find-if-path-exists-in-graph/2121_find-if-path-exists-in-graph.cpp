/*
 * Problem  : 2121. Find if Path Exists in Graph
 * Difficulty: Easy
 * Topics   : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
 * URL      : https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

class Solution {
public:

    bool dfs(int src, int des, vector<int> adj[], vector<int> &vis){
        vis[src]=1;

        if(src==des){
            return true;
        }
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(it,des,adj,vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        return dfs(source,destination,adj,vis);
    }
};