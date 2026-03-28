/*
 * Problem  : 1428. Jump Game III
 * Difficulty: Medium
 * Topics   : Array, Depth-First Search, Breadth-First Search
 * URL      : https://leetcode.com/problems/jump-game-iii/
 */

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>q;
        q.push(start);
        vector<int> vis(n,0);
        while(!q.empty()){
            int ind=q.front();
            q.pop();

            vis[ind]=1;
            if(arr[ind]==0){
                return true;
            }
            // if(ind>=arr[ind] && arr[ind-arr[ind]]==0){
            //     return true;
            // }
            // if(ind+arr[ind]<n && arr[ind_arr[ind]]==0){
            //     return true;
            // }
            if(ind+arr[ind]<n && !vis[ind+arr[ind]]){
                q.push(ind+arr[ind]);
            }
            if(ind>=arr[ind] && !vis[ind-arr[ind]]){
                q.push(ind-arr[ind]);
            }
        }
        return false;
    }
};