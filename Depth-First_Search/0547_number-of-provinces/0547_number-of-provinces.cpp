/*
 * Problem  : 547. Number of Provinces
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
 * URL      : https://leetcode.com/problems/number-of-provinces/
 */

class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>> &isConnected){
        vis[i]=1;
        for(int j=0;j<vis.size();j++){
            if(!vis[j]&&isConnected[i][j]){
                dfs(j,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count;
    }
};