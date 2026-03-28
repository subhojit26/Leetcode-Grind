/*
 * Problem  : 1447. Jump Game IV
 * Difficulty: Hard
 * Topics   : Array, Hash Table, Breadth-First Search
 * URL      : https://leetcode.com/problems/jump-game-iv/
 */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool>visited(n, false);
        q.push(0);
        int step=0;

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                if(curr==n-1){
                    return step;
                }
                if(curr+1<n && !visited[curr+1]){
                    visited[curr+1]=true;
                    q.push(curr+1);
                }
                if(curr-1>=0 && !visited[curr-1]){
                    visited[curr-1]=true;
                    q.push(curr-1);
                }
                for(int it:mp[arr[curr]]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push(it);
                    }
                }
                mp[arr[curr]].clear();
            }
            step++;
        }
        return -1;
    }
};