/*
 * Problem  : 3058. Maximum Number of K-Divisible Components
 * Difficulty: Hard
 * Topics   : Tree, Depth-First Search
 * URL      : https://leetcode.com/problems/maximum-number-of-k-divisible-components/
 */

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<long long>> gr(n);
        vector<long long> indegree(n);
        vector<long long> nodeValues(values.begin(),values.end());
        if(n==1){
            return 1;
        }

        for(auto edge:edges){
            long long u=edge[0];
            long long v=edge[1];

            gr[u].push_back(v);
            gr[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<long long> q;
        for(long long i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        long long components=0;

        while(!q.empty()){
            long long cur=q.front();
            q.pop();
            indegree[cur]--;

            long long addValue=(nodeValues[cur]%k==0)?0:nodeValues[cur];
            if(addValue==0){
                components++;
            }

            for(auto neighbour:gr[cur]){
                if(indegree[neighbour]>0){
                    indegree[neighbour]--;
                    nodeValues[neighbour]+=addValue;
                    if(indegree[neighbour]==1){
                        q.push(neighbour);
                    }
                }
            }
        }
        return components;

    }
};