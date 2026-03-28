/*
 * Problem  : 2531. Create Components With Same Value
 * Difficulty: Hard
 * Topics   : Array, Math, Tree, Depth-First Search, Enumeration
 * URL      : https://leetcode.com/problems/create-components-with-same-value/
 */

class Solution {
public:

    bool bfs(int target, vector<int> indegree, vector<vector<int>> gr, vector<int> values){
        queue<int> q;
        for(int i=0;i<values.size();i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            indegree[cur]=0;
            for(auto nxt:gr[cur]){
                if(values[cur]!=target){
                    values[nxt]+=values[cur];
                }
                indegree[nxt]--;
                if(indegree[nxt]==0){
                    if(values[nxt]==target){
                        return true;
                    }else{
                        return false;
                    }
                }
                if(indegree[nxt]==1){
                    q.push(nxt);
                }
            }
        }
        return true;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> gr(n);
        vector<int> indegree(n,0);
        int ss=accumulate(nums.begin(),nums.end(),0);
        int ans;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        for(int i=*min_element(nums.begin(),nums.end());i<ss;i++){
            if(ss%i==0 && bfs(i,indegree,gr,nums)){
                return ss/i-1;
            }
        }
        return 0;
    }
};