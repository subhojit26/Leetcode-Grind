/*
 * Problem  : 1833. Find the Highest Altitude
 * Difficulty: Easy
 * Topics   : Array, Prefix Sum
 * URL      : https://leetcode.com/problems/find-the-highest-altitude/
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height=0;
        int mx=0;
        for(int i=0;i<gain.size();i++){
            height=height+gain[i];
            mx=max(mx,height);
        }
        return mx;
    }
};