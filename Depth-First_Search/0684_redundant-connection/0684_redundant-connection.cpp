/*
 * Problem  : 684. Redundant Connection
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
 * URL      : https://leetcode.com/problems/redundant-connection/
 */

class Disjoint{
    vector<int> parent, rank;
    public:
    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUltPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltPar(parent[node]);
    }

    bool unionByRank(int u, int v){
        int ultU = findUltPar(u);
        int ultV = findUltPar(v);
        
        if(ultU == ultV){
            return false; // Cycle detected
        }
        
        if(rank[ultU] < rank[ultV]){
            parent[ultU] = ultV;
        }
        else if(rank[ultV] < rank[ultU]){
            parent[ultV] = ultU;
        }else{
            parent[ultV] = ultU;
            rank[ultU]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint dsu(n);
        
        for(auto &edge : edges){
            if(!dsu.unionByRank(edge[0], edge[1])){
                return edge; // The edge that forms a cycle
            }
        }
        return {};
    }
};
