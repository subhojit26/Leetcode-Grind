/*
 * Problem  : 1798. Max Number of K-Sum Pairs
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Two Pointers, Sorting
 * URL      : https://leetcode.com/problems/max-number-of-k-sum-pairs/
 */

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int op=0;
        for (int x : nums) {
            int need = k - x;

            if (mp[need] > 0) {
                op++;
                mp[need]--;
            } else {
                mp[x]++;
            }
        }
        return op;
    }
};