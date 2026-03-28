/*
 * Problem  : 310. Minimum Height Trees
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
 * URL      : https://leetcode.com/problems/minimum-height-trees/
 */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }

        for(int i=0;i<edges.size();i++){
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }

        while(n>2){
            int sz=q.size();
            n-=sz;

            while(sz>0){
                int ele=q.front();
                q.pop();

                for(auto it:adj[ele]){
                    deg[it]--;
                    if(deg[it]==1){
                        q.push(it);
                    }
                }
                sz--;
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};