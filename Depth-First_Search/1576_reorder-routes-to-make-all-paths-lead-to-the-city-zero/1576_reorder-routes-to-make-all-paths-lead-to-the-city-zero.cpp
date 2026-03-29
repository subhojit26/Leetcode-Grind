/*
 * Problem  : 1576. Reorder Routes to Make All Paths Lead to the City Zero
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory
 * URL      : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 */

class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<int> &vis, int from){
        int count=0;
        vis[from]=1;
        for(auto it:adj[from]){
            if(!vis[abs(it)]){
                count+=dfs(adj,vis,abs(it))+(it>0);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        return dfs(adj,vis,0);
    }
};