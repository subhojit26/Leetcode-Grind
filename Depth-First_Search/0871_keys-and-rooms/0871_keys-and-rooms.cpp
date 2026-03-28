/*
 * Problem  : 871. Keys and Rooms
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory
 * URL      : https://leetcode.com/problems/keys-and-rooms/
 */

class Solution {
public:
    void dfs(int ind, vector<vector<int>> &rooms, vector<int> &vis){
        vis[ind]=1;
        for(auto it:rooms[ind]){
            if(vis[it]==0){
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};