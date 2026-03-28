/*
 * Problem  : 803. Cheapest Flights Within K Stops
 * Difficulty: Medium
 * Topics   : Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path
 * URL      : https://leetcode.com/problems/cheapest-flights-within-k-stops/
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int, pair<int,int>>> pq;
        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;

        while(!pq.empty()){
            int stops=pq.front().first;
            int node=pq.front().second.first;
            int cost=pq.front().second.second;
            pq.pop();

            if(stops>k){
                continue;
            }

            for(auto it:adj[node]){
                int adjNode=it.first;
                int edW=it.second;

                if(edW+cost<dist[adjNode] && stops<=k){
                    dist[adjNode]=edW+cost;
                    pq.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};