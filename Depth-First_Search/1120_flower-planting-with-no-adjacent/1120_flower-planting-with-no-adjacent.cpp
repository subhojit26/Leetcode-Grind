/*
 * Problem  : 1120. Flower Planting With No Adjacent
 * Difficulty: Medium
 * Topics   : Depth-First Search, Breadth-First Search, Graph Theory
 * URL      : https://leetcode.com/problems/flower-planting-with-no-adjacent/
 */

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Create an adjacency list for the gardens
        vector<vector<int>> adj(n);
        for (auto& path : paths) {
            adj[path[0] - 1].push_back(path[1] - 1);
            adj[path[1] - 1].push_back(path[0] - 1);
        }

        // Array to store the flower type for each garden
        vector<int> flowers(n, 0);

        // Assign flower types
        for (int i = 0; i < n; ++i) {
            // Check which flower types are already used by neighbors
            bool used[5] = {false}; // We only care about indices 1 to 4
            for (int neighbor : adj[i]) {
                if (flowers[neighbor] != 0) {
                    used[flowers[neighbor]] = true;
                }
            }

            // Assign the first unused flower type
            for (int flower = 1; flower <= 4; ++flower) {
                if (!used[flower]) {
                    flowers[i] = flower;
                    break;
                }
            }
        }

        return flowers;
    }
};
