/*
 * Problem  : 646. Maximum Length of Pair Chain
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Greedy, Sorting
 * URL      : https://leetcode.com/problems/maximum-length-of-pair-chain/
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int curr_end = INT_MIN;
        int count = 0;

        for (const auto& pair : pairs) {
            if (pair[0] > curr_end) {
                count++;
                curr_end = pair[1];
            }
        }

        return count;
    }
};