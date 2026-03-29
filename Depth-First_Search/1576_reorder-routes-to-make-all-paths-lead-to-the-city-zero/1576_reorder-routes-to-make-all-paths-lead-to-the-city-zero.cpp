/*
 * Problem  : 1576. Reorder Routes to Make All Paths Lead to the City Zero
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory
 * URL      : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 */

class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<int> &vis,int from){
        int change=0;
        vis[from]=1;
        for(auto to:adj[from]){
            if(!vis[abs(to)]){
                change+=dfs(adj,vis,abs(to))+(to>0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        vector<int> vis(n,0);
        return dfs(adj,vis,0);
        
    }
};