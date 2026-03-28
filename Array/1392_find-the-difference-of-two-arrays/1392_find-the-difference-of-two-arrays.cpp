/*
 * Problem  : 1392. Find the Difference of Two Arrays
 * Difficulty: Easy
 * Topics   : Array, Hash Table
 * URL      : https://leetcode.com/problems/find-the-difference-of-two-arrays/
 */

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]] = 1;
        }

        for (int i = 0; i < nums2.size(); i++) {
            mp2[nums2[i]] = 1;
        }

        vector<int> t1, t2;
        for (auto it : mp1) {
            if (mp2.find(it.first) == mp2.end()) {
                t1.push_back(it.first);
            }
        }

        for (auto it : mp2) {
            if (mp1.find(it.first) == mp1.end()) {
                t2.push_back(it.first);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(t1);
        ans.push_back(t2);
        return ans;
    }
};