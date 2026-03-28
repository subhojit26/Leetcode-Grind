/*
 * Problem  : 984. Most Stones Removed with Same Row or Column
 * Difficulty: Medium
 * Topics   : Hash Table, Depth-First Search, Union-Find, Graph Theory
 * URL      : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 */

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;

        // Find maximum row and column indices
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Initialize DisjointSet for rows and columns
        DisjointSet ds(maxRow + maxCol + 2); // Offset rows and columns to avoid overlap

        // Union stones based on row and column
        for (auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1; // Offset columns
            ds.unionByRank(rowNode, colNode);
        }

        // Count connected components
        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            int rowNode = stone[0];
            uniqueRoots.insert(ds.findUPar(rowNode));
        }

        // Total removable stones = Total stones - Number of unique connected components
        return stones.size() - uniqueRoots.size();
    }
};